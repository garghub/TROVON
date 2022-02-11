static int
F_1 ( struct V_1 * V_1 , const void * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
unsigned long V_6 ;
int V_7 ;
T_1 V_8 = 0 ;
const char * V_9 = V_2 , * V_10 , * V_11 ;
F_2 ( L_1 ,
V_1 -> V_12 , V_1 -> V_13 ,
( int ) V_3 , ( int ) V_3 , V_9 , V_3 ) ;
if ( V_3 <= 1 || ! V_9 || V_9 [ V_3 - 1 ] != '\0' )
return - V_14 ;
V_3 -- ;
V_10 = V_9 + V_3 ;
V_11 = memchr ( V_9 , '#' , V_3 ) ;
if ( ! V_11 ) {
F_3 ( L_2 ) ;
V_8 = V_3 ;
} else {
const char * V_15 ;
V_8 = V_11 - V_9 ;
V_11 ++ ;
F_3 ( L_3 , V_11 ) ;
do {
const char * V_16 ;
int V_17 , V_18 , V_19 , V_20 ;
V_15 = memchr ( V_11 , '#' , V_10 - V_11 ) ? : V_10 ;
V_17 = V_15 - V_11 ;
if ( ! V_17 ) {
F_4 ( V_21
L_4 ,
V_1 -> V_12 ) ;
return - V_14 ;
}
V_16 = memchr ( V_11 , '=' , V_17 ) ? : V_10 ;
V_18 = V_16 - V_11 ;
V_16 ++ ;
V_19 = V_15 - V_16 ;
V_20 = V_19 >= 0 ? V_19 : 0 ;
F_3 ( L_5 ,
V_18 , V_18 , V_11 , V_20 , V_20 , V_16 ) ;
if ( V_18 == sizeof( V_22 ) - 1 &&
memcmp ( V_11 , V_22 , V_18 ) == 0 ) {
F_3 ( L_6 ) ;
if ( V_19 <= 0 )
goto V_23;
V_7 = F_5 ( V_16 , 10 , & V_6 ) ;
if ( V_7 < 0 )
goto V_23;
if ( V_6 < 1 || V_6 > 511 )
goto V_23;
F_3 ( L_7 , V_6 ) ;
V_1 -> V_24 . V_25 [ 0 ] = - V_6 ;
continue;
}
V_23:
F_4 ( V_21
L_8
L_9 ,
V_18 , V_18 , V_11 , V_1 -> V_12 ) ;
return - V_14 ;
} while ( V_11 = V_15 + 1 , V_11 < V_10 );
}
if ( V_1 -> V_24 . V_25 [ 0 ] ) {
F_6 ( L_10 , V_1 -> V_24 . V_25 [ 0 ] ) ;
return 0 ;
}
F_3 ( L_11 ) ;
V_7 = F_7 ( V_1 , V_8 ) ;
if ( V_7 < 0 )
return - V_14 ;
V_5 = F_8 ( sizeof( * V_5 ) + V_8 + 1 , V_26 ) ;
if ( ! V_5 ) {
F_6 ( L_12 ) ;
return - V_27 ;
}
V_5 -> V_3 = V_8 ;
memcpy ( V_5 -> V_9 , V_9 , V_8 ) ;
V_5 -> V_9 [ V_8 ] = '\0' ;
F_9 ( V_1 -> V_28 . V_9 , V_5 ) ;
F_6 ( L_13 ) ;
return 0 ;
}
static int
F_10 ( const struct V_1 * V_1 , const void * V_13 )
{
int V_29 , V_30 , V_7 = 0 ;
const char * V_31 = V_1 -> V_13 , * V_32 = V_13 ;
F_2 ( L_14 , V_31 , V_32 ) ;
if ( ! V_31 || ! V_32 )
goto V_33;
if ( strcasecmp ( V_31 , V_32 ) == 0 )
goto V_34;
V_29 = strlen ( V_31 ) ;
V_30 = strlen ( V_32 ) ;
if ( V_29 <= 0 || V_30 <= 0 )
goto V_33;
if ( V_31 [ V_29 - 1 ] == '.' )
V_29 -- ;
if ( V_32 [ V_30 - 1 ] == '.' )
V_30 -- ;
if ( V_29 != V_30 || strncasecmp ( V_31 , V_32 , V_29 ) != 0 )
goto V_33;
V_34:
V_7 = 1 ;
V_33:
F_6 ( L_15 , V_7 ) ;
return V_7 ;
}
static void F_11 ( const struct V_1 * V_1 , struct V_35 * V_36 )
{
int V_37 = V_1 -> V_24 . V_25 [ 0 ] ;
F_12 ( V_36 , V_1 -> V_13 ) ;
if ( F_13 ( V_1 ) ) {
if ( V_37 )
F_14 ( V_36 , L_16 , V_37 ) ;
else
F_14 ( V_36 , L_17 , V_1 -> V_3 ) ;
}
}
static long F_15 ( const struct V_1 * V_1 ,
char T_2 * V_38 , T_1 V_39 )
{
if ( V_1 -> V_24 . V_25 [ 0 ] )
return V_1 -> V_24 . V_25 [ 0 ] ;
return F_16 ( V_1 , V_38 , V_39 ) ;
}
static int T_3 F_17 ( void )
{
struct V_40 * V_40 ;
struct V_1 * V_41 ;
int V_7 ;
F_4 ( V_42 L_18 ,
V_43 . V_44 ) ;
V_40 = F_18 ( NULL ) ;
if ( ! V_40 )
return - V_27 ;
V_41 = F_19 ( & V_45 , L_19 , 0 , 0 , V_40 ,
( V_46 & ~ V_47 ) |
V_48 | V_49 ,
V_50 ) ;
if ( F_20 ( V_41 ) ) {
V_7 = F_21 ( V_41 ) ;
goto V_51;
}
V_7 = F_22 ( V_41 , NULL , 0 , NULL , NULL ) ;
if ( V_7 < 0 )
goto V_52;
V_7 = F_23 ( & V_43 ) ;
if ( V_7 < 0 )
goto V_52;
F_24 ( V_53 , & V_41 -> V_54 ) ;
V_40 -> V_55 = V_41 ;
V_40 -> V_56 = V_57 ;
V_58 = V_40 ;
F_3 ( L_20 , F_25 ( V_41 ) ) ;
return 0 ;
V_52:
F_26 ( V_41 ) ;
V_51:
F_27 ( V_40 ) ;
return V_7 ;
}
static void T_4 F_28 ( void )
{
F_29 ( V_58 -> V_55 ) ;
F_30 ( & V_43 ) ;
F_27 ( V_58 ) ;
F_4 ( V_42 L_21 ,
V_43 . V_44 ) ;
}
