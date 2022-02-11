static void F_1 ( void )
{
T_1 V_1 ;
T_1 V_2 ;
static char * V_3 [] = { L_1 , L_2 , L_3 } ;
int V_4 ;
bool V_5 = false ;
union V_6 V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( V_11 == NULL ) {
F_2 ( L_4 , V_12 ) ;
return;
}
for ( V_4 = 0 ; V_4 < F_3 ( V_3 ) ; V_4 ++ ) {
V_9 = F_4 ( V_3 [ V_4 ] ) ;
if ( ! V_9 )
continue;
V_10 = V_9 -> V_13 ( V_9 , V_14 , & V_7 ) ;
if ( ! V_10 && V_7 . V_15 ) {
V_5 = true ;
break;
}
}
if ( ! V_5 )
goto V_16;
V_9 = F_4 ( L_5 ) ;
if ( V_9 ) {
V_10 = V_9 -> V_13 ( V_9 , V_17 ,
& V_7 ) ;
if ( ! V_10 && V_7 . V_15 != V_18 ) {
F_5 ( V_19
L_6
L_7 ,
V_3 [ V_4 ] ) ;
F_6 ( L_8 ) ;
}
}
V_16:
F_7 ( & V_2 ) ;
if ( ! F_8 ( V_20 , & V_2 , & V_1 ) ) {
( void ) F_9 ( V_21 ,
V_22 |
V_23 ) ;
( void ) F_8 ( V_24 , & V_1 , NULL ) ;
}
}
void F_10 ( char V_25 , const char * V_26 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
T_2 V_31 = 0 ;
T_3 V_7 ;
if ( V_11 == NULL ) {
F_2 ( L_4 , V_12 ) ;
return;
}
V_28 = F_11 ( V_11 -> V_32 ) ;
V_30 = V_28 -> V_33 ;
if ( V_30 && V_30 -> V_34 )
V_31 = V_30 -> V_34 ( V_26 ) ;
else
F_12 ( L_9 ,
V_12 , V_31 ) ;
F_13 ( V_11 , V_35 ,
V_36 , & V_7 ) ;
F_14 ( V_11 , V_35 ,
V_36 , ( V_7 & ~ V_37 ) ) ;
V_7 = V_31 & 0xFF ;
F_14 ( V_11 , V_35 ,
V_38 , V_7 ) ;
V_7 = ( V_31 >> 8 ) & 0xFF ;
F_14 ( V_11 , V_35 ,
V_39 , V_7 ) ;
F_15 ( V_40 , 0xFF , 0x0 ) ;
F_15 ( V_41 , 0xFF , ( V_42 |
V_43 | V_44 ) ) ;
}
static inline bool F_16 ( T_3 V_45 )
{
return ( ( V_45 == V_46 ) ||
( V_45 == V_47 ) ) ;
}
int F_17 ( T_2 V_48 , T_3 * V_49 )
{
T_3 V_45 ;
if ( V_11 == NULL )
return - V_50 ;
V_45 = ( V_48 >> 8 ) ;
if ( ! F_16 ( V_45 ) )
return - V_50 ;
return F_13 ( V_11 , V_45 ,
( T_3 ) ( V_48 & 0xFF ) , V_49 ) ;
}
int F_15 ( T_2 V_48 , T_3 V_51 , T_3 V_49 )
{
T_3 V_45 ;
if ( V_11 == NULL )
return - V_50 ;
V_45 = ( V_48 >> 8 ) ;
if ( ! F_16 ( V_45 ) )
return - V_50 ;
return F_18 ( V_11 , V_45 ,
( T_3 ) ( V_48 & 0xFF ) , V_51 , V_49 ) ;
}
static int F_19 ( struct V_52 * V_53 )
{
struct V_54 * V_54 = F_20 ( V_53 -> V_55 . V_32 ) ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_28 = F_11 ( V_53 -> V_55 . V_32 ) ;
if ( ! V_28 )
return - V_50 ;
V_11 = & V_53 -> V_55 ;
if ( ! V_56 )
V_56 = F_1 ;
V_30 = V_28 -> V_33 ;
if ( V_30 ) {
int V_57 , V_10 , V_4 , V_58 ;
if ( F_21 ( V_54 ) )
V_57 = V_59 ;
else
V_57 = V_60 ;
for ( V_4 = V_61 ; V_4 <= V_57 ; V_4 ++ ) {
V_58 = V_4 - V_61 ;
V_10 = F_15 ( V_4 , 0xff ,
V_30 -> V_62 [ V_58 ] ) ;
F_22 ( & V_53 -> V_55 ,
L_10 ,
V_58 + 1 ,
V_30 -> V_62 [ V_58 ] ) ;
if ( V_10 < 0 ) {
F_23 ( & V_53 -> V_55 ,
L_11
L_12 , V_58 + 1 , V_10 ) ;
}
}
}
return 0 ;
}
static int F_24 ( struct V_52 * V_53 )
{
V_11 = NULL ;
if ( V_56 == F_1 )
V_56 = NULL ;
return 0 ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_63 ) ;
}
