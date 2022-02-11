static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
unsigned long V_6 ;
int V_7 ;
T_1 V_8 = V_3 -> V_8 , V_9 = 0 ;
const char * V_10 = V_3 -> V_10 , * V_11 , * V_12 ;
F_2 ( L_1 ,
V_1 -> V_13 , V_1 -> V_14 ,
( int ) V_8 , ( int ) V_8 , V_10 , V_8 ) ;
if ( V_8 <= 1 || ! V_10 || V_10 [ V_8 - 1 ] != '\0' )
return - V_15 ;
V_8 -- ;
V_11 = V_10 + V_8 ;
V_12 = memchr ( V_10 , '#' , V_8 ) ;
if ( ! V_12 ) {
F_3 ( L_2 ) ;
V_9 = V_8 ;
} else {
const char * V_16 ;
V_9 = V_12 - V_10 ;
V_12 ++ ;
F_3 ( L_3 , V_12 ) ;
do {
const char * V_17 ;
int V_18 , V_19 , V_20 , V_21 ;
V_16 = memchr ( V_12 , '#' , V_11 - V_12 ) ? : V_11 ;
V_18 = V_16 - V_12 ;
if ( ! V_18 ) {
F_4 ( V_22
L_4 ,
V_1 -> V_13 ) ;
return - V_15 ;
}
V_17 = memchr ( V_12 , '=' , V_18 ) ? : V_11 ;
V_19 = V_17 - V_12 ;
V_17 ++ ;
V_20 = V_16 - V_17 ;
V_21 = V_20 >= 0 ? V_20 : 0 ;
F_3 ( L_5 ,
V_19 , V_19 , V_12 , V_21 , V_21 , V_17 ) ;
if ( V_19 == sizeof( V_23 ) - 1 &&
memcmp ( V_12 , V_23 , V_19 ) == 0 ) {
F_3 ( L_6 ) ;
if ( V_20 <= 0 )
goto V_24;
V_7 = F_5 ( V_17 , 10 , & V_6 ) ;
if ( V_7 < 0 )
goto V_24;
if ( V_6 < 1 || V_6 > 511 )
goto V_24;
F_3 ( L_7 , V_6 ) ;
V_1 -> V_25 . V_26 [ 0 ] = - V_6 ;
continue;
}
V_24:
F_4 ( V_22
L_8
L_9 ,
V_19 , V_19 , V_12 , V_1 -> V_13 ) ;
return - V_15 ;
} while ( V_12 = V_16 + 1 , V_12 < V_11 );
}
if ( V_1 -> V_25 . V_26 [ 0 ] ) {
F_6 ( L_10 , V_1 -> V_25 . V_26 [ 0 ] ) ;
return 0 ;
}
F_3 ( L_11 ) ;
V_7 = F_7 ( V_1 , V_9 ) ;
if ( V_7 < 0 )
return - V_15 ;
V_5 = F_8 ( sizeof( * V_5 ) + V_9 + 1 , V_27 ) ;
if ( ! V_5 ) {
F_6 ( L_12 ) ;
return - V_28 ;
}
V_5 -> V_8 = V_9 ;
memcpy ( V_5 -> V_10 , V_10 , V_9 ) ;
V_5 -> V_10 [ V_9 ] = '\0' ;
F_9 ( V_1 -> V_29 . V_10 , V_5 ) ;
F_6 ( L_13 ) ;
return 0 ;
}
static int
F_10 ( const struct V_1 * V_1 , const void * V_14 )
{
int V_30 , V_31 , V_7 = 0 ;
const char * V_32 = V_1 -> V_14 , * V_33 = V_14 ;
F_2 ( L_14 , V_32 , V_33 ) ;
if ( ! V_32 || ! V_33 )
goto V_34;
if ( strcasecmp ( V_32 , V_33 ) == 0 )
goto V_35;
V_30 = strlen ( V_32 ) ;
V_31 = strlen ( V_33 ) ;
if ( V_30 <= 0 || V_31 <= 0 )
goto V_34;
if ( V_32 [ V_30 - 1 ] == '.' )
V_30 -- ;
if ( V_33 [ V_31 - 1 ] == '.' )
V_31 -- ;
if ( V_30 != V_31 || strncasecmp ( V_32 , V_33 , V_30 ) != 0 )
goto V_34;
V_35:
V_7 = 1 ;
V_34:
F_6 ( L_15 , V_7 ) ;
return V_7 ;
}
static void F_11 ( const struct V_1 * V_1 , struct V_36 * V_37 )
{
int V_38 = V_1 -> V_25 . V_26 [ 0 ] ;
F_12 ( V_37 , V_1 -> V_14 ) ;
if ( F_13 ( V_1 ) ) {
if ( V_38 )
F_14 ( V_37 , L_16 , V_38 ) ;
else
F_14 ( V_37 , L_17 , V_1 -> V_8 ) ;
}
}
static long F_15 ( const struct V_1 * V_1 ,
char T_2 * V_39 , T_1 V_40 )
{
if ( V_1 -> V_25 . V_26 [ 0 ] )
return V_1 -> V_25 . V_26 [ 0 ] ;
return F_16 ( V_1 , V_39 , V_40 ) ;
}
static int T_3 F_17 ( void )
{
struct V_41 * V_41 ;
struct V_1 * V_42 ;
int V_7 ;
V_41 = F_18 ( NULL ) ;
if ( ! V_41 )
return - V_28 ;
V_42 = F_19 ( & V_43 , L_18 ,
V_44 , V_45 , V_41 ,
( V_46 & ~ V_47 ) |
V_48 | V_49 ,
V_50 ) ;
if ( F_20 ( V_42 ) ) {
V_7 = F_21 ( V_42 ) ;
goto V_51;
}
V_7 = F_22 ( V_42 , NULL , 0 , NULL , NULL ) ;
if ( V_7 < 0 )
goto V_52;
V_7 = F_23 ( & V_53 ) ;
if ( V_7 < 0 )
goto V_52;
F_24 ( V_54 , & V_42 -> V_55 ) ;
V_41 -> V_56 = V_42 ;
V_41 -> V_57 = V_58 ;
V_59 = V_41 ;
F_3 ( L_19 , F_25 ( V_42 ) ) ;
return 0 ;
V_52:
F_26 ( V_42 ) ;
V_51:
F_27 ( V_41 ) ;
return V_7 ;
}
static void T_4 F_28 ( void )
{
F_29 ( V_59 -> V_56 ) ;
F_30 ( & V_53 ) ;
F_27 ( V_59 ) ;
}
