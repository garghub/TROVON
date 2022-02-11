static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
int V_6 ;
int V_7 = V_2 -> V_7 , V_8 = 0 ;
const char * V_9 = V_2 -> V_9 , * V_10 , * V_11 ;
F_2 ( L_1 , V_7 , V_7 , V_9 , V_7 ) ;
if ( V_7 <= 1 || ! V_9 || V_9 [ V_7 - 1 ] != '\0' )
return - V_12 ;
V_7 -- ;
V_10 = V_9 + V_7 ;
V_11 = memchr ( V_9 , '#' , V_7 ) ;
if ( ! V_11 ) {
F_3 ( L_2 ) ;
V_8 = V_7 ;
} else {
const char * V_13 ;
V_8 = V_11 - V_9 ;
V_11 ++ ;
F_3 ( L_3 , V_11 ) ;
do {
const char * V_14 ;
int V_15 , V_16 , V_17 , V_18 ;
V_13 = memchr ( V_11 , '#' , V_10 - V_11 ) ? : V_10 ;
V_15 = V_13 - V_11 ;
if ( ! V_15 ) {
F_4 ( V_19
L_4 ) ;
return - V_12 ;
}
V_14 = memchr ( V_11 , '=' , V_15 ) ? : V_10 ;
V_16 = V_14 - V_11 ;
V_14 ++ ;
V_17 = V_13 - V_14 ;
V_18 = V_17 >= 0 ? V_17 : 0 ;
F_3 ( L_5 ,
V_16 , V_16 , V_11 , V_18 , V_18 , V_14 ) ;
if ( V_16 == sizeof( V_20 ) - 1 &&
memcmp ( V_11 , V_20 , V_16 ) == 0 ) {
F_3 ( L_6 ) ;
if ( V_17 <= 0 )
goto V_21;
V_6 = F_5 ( V_14 , 10 , & V_5 ) ;
if ( V_6 < 0 )
goto V_21;
if ( V_5 < 1 || V_5 > 511 )
goto V_21;
F_3 ( L_7 , V_5 ) ;
V_2 -> V_22 [ 0 ] = F_6 ( - V_5 ) ;
continue;
}
V_21:
F_4 ( V_19
L_8
L_9 ,
V_16 , V_16 , V_11 ) ;
return - V_12 ;
} while ( V_11 = V_13 + 1 , V_11 < V_10 );
}
if ( V_2 -> V_22 [ 0 ] ) {
F_7 ( L_10 , F_8 ( V_2 -> V_22 [ 0 ] ) ) ;
return 0 ;
}
F_3 ( L_11 ) ;
V_2 -> V_23 = V_8 ;
V_4 = F_9 ( sizeof( * V_4 ) + V_8 + 1 , V_24 ) ;
if ( ! V_4 ) {
F_7 ( L_12 ) ;
return - V_25 ;
}
V_4 -> V_7 = V_8 ;
memcpy ( V_4 -> V_9 , V_9 , V_8 ) ;
V_4 -> V_9 [ V_8 ] = '\0' ;
V_2 -> V_26 [ 0 ] = V_4 ;
F_7 ( L_13 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( L_14 , V_27 ) ;
F_12 ( V_2 -> V_26 [ 0 ] ) ;
}
static int
F_13 ( const struct V_28 * V_28 , const void * V_29 )
{
int V_30 , V_31 , V_6 = 0 ;
const char * V_32 = V_28 -> V_29 , * V_33 = V_29 ;
F_2 ( L_15 , V_32 , V_33 ) ;
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
V_6 = 1 ;
V_34:
F_7 ( L_16 , V_6 ) ;
return V_6 ;
}
static void F_14 ( const struct V_28 * V_28 , struct V_36 * V_37 )
{
int V_38 = V_28 -> V_22 . V_39 [ 0 ] ;
F_15 ( V_37 , V_28 -> V_29 ) ;
if ( F_16 ( V_28 ) ) {
if ( V_38 )
F_17 ( V_37 , L_17 , V_38 ) ;
else
F_17 ( V_37 , L_18 , V_28 -> V_7 ) ;
}
}
static long F_18 ( const struct V_28 * V_28 ,
char T_1 * V_40 , T_2 V_41 )
{
if ( V_28 -> V_22 . V_39 [ 0 ] )
return V_28 -> V_22 . V_39 [ 0 ] ;
return F_19 ( V_28 , V_40 , V_41 ) ;
}
static int T_3 F_20 ( void )
{
struct V_42 * V_42 ;
struct V_28 * V_43 ;
int V_6 ;
V_42 = F_21 ( NULL ) ;
if ( ! V_42 )
return - V_25 ;
V_43 = F_22 ( L_19 ,
V_44 , V_45 , V_42 ,
( V_46 & ~ V_47 ) |
V_48 | V_49 ,
V_50 , NULL ) ;
if ( F_23 ( V_43 ) ) {
V_6 = F_8 ( V_43 ) ;
goto V_51;
}
V_6 = F_24 ( & V_52 ) ;
if ( V_6 < 0 )
goto V_53;
F_25 ( V_54 , & V_43 -> V_55 ) ;
V_42 -> V_56 = V_43 ;
V_42 -> V_57 = V_58 ;
V_59 = V_42 ;
F_3 ( L_20 , F_26 ( V_43 ) ) ;
return 0 ;
V_53:
F_27 ( V_43 ) ;
V_51:
F_28 ( V_42 ) ;
return V_6 ;
}
static void T_4 F_29 ( void )
{
F_30 ( V_59 -> V_56 ) ;
F_31 ( & V_52 ) ;
F_28 ( V_59 ) ;
}
