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
static bool F_13 ( const struct V_28 * V_28 ,
const struct V_29 * V_30 )
{
int V_31 , V_32 , V_6 = 0 ;
const char * V_33 = V_28 -> V_34 , * V_35 = V_30 -> V_36 ;
F_2 ( L_15 , V_33 , V_35 ) ;
if ( ! V_33 || ! V_35 )
goto V_37;
if ( strcasecmp ( V_33 , V_35 ) == 0 )
goto V_38;
V_31 = strlen ( V_33 ) ;
V_32 = strlen ( V_35 ) ;
if ( V_31 <= 0 || V_32 <= 0 )
goto V_37;
if ( V_33 [ V_31 - 1 ] == '.' )
V_31 -- ;
if ( V_35 [ V_32 - 1 ] == '.' )
V_32 -- ;
if ( V_31 != V_32 || strncasecmp ( V_33 , V_35 , V_31 ) != 0 )
goto V_37;
V_38:
V_6 = 1 ;
V_37:
F_7 ( L_16 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_29 * V_30 )
{
V_30 -> V_39 = V_40 ;
V_30 -> V_41 = F_13 ;
return 0 ;
}
static void F_15 ( const struct V_28 * V_28 , struct V_42 * V_43 )
{
int V_44 = V_28 -> V_22 . V_45 [ 0 ] ;
F_16 ( V_43 , V_28 -> V_34 ) ;
if ( F_17 ( V_28 ) ) {
if ( V_44 )
F_18 ( V_43 , L_17 , V_44 ) ;
else
F_18 ( V_43 , L_18 , V_28 -> V_7 ) ;
}
}
static long F_19 ( const struct V_28 * V_28 ,
char T_1 * V_46 , T_2 V_47 )
{
if ( V_28 -> V_22 . V_45 [ 0 ] )
return V_28 -> V_22 . V_45 [ 0 ] ;
return F_20 ( V_28 , V_46 , V_47 ) ;
}
static int T_3 F_21 ( void )
{
struct V_48 * V_48 ;
struct V_28 * V_49 ;
int V_6 ;
V_48 = F_22 ( NULL ) ;
if ( ! V_48 )
return - V_25 ;
V_49 = F_23 ( L_19 ,
V_50 , V_51 , V_48 ,
( V_52 & ~ V_53 ) |
V_54 | V_55 ,
V_56 , NULL ) ;
if ( F_24 ( V_49 ) ) {
V_6 = F_8 ( V_49 ) ;
goto V_57;
}
V_6 = F_25 ( & V_58 ) ;
if ( V_6 < 0 )
goto V_59;
F_26 ( V_60 , & V_49 -> V_61 ) ;
V_48 -> V_62 = V_49 ;
V_48 -> V_63 = V_64 ;
V_65 = V_48 ;
F_3 ( L_20 , F_27 ( V_49 ) ) ;
return 0 ;
V_59:
F_28 ( V_49 ) ;
V_57:
F_29 ( V_48 ) ;
return V_6 ;
}
static void T_4 F_30 ( void )
{
F_31 ( V_65 -> V_62 ) ;
F_32 ( & V_58 ) ;
F_29 ( V_65 ) ;
}
