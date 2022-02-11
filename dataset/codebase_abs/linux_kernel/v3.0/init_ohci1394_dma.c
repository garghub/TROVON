static inline void F_1 ( const struct V_1 * V_1 , int V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_1 -> V_4 + V_2 ) ;
}
static inline T_1 F_3 ( const struct V_1 * V_1 , int V_2 )
{
return F_4 ( V_1 -> V_4 + V_2 ) ;
}
static inline T_2 T_3 F_5 ( struct V_1 * V_1 , T_2 V_5 )
{
int V_6 ;
T_1 V_7 ;
F_1 ( V_1 , V_8 , ( V_5 << 8 ) | 0x00008000 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( F_3 ( V_1 , V_8 ) & 0x80000000 )
break;
F_6 ( 1 ) ;
}
V_7 = F_3 ( V_1 , V_8 ) ;
return ( V_7 & 0x00ff0000 ) >> 16 ;
}
static inline void T_3 F_7 ( struct V_1 * V_1 , T_2 V_5 , T_2 V_3 )
{
int V_6 ;
F_1 ( V_1 , V_8 , ( V_5 << 8 ) | V_3 | 0x00004000 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( ! ( F_3 ( V_1 , V_8 ) & 0x00004000 ) )
break;
F_6 ( 1 ) ;
}
}
static inline void T_3 F_8 ( struct V_1 * V_1 )
{
int V_6 ;
F_1 ( V_1 , V_10 , V_11 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( ! ( F_3 ( V_1 , V_10 )
& V_11 ) )
break;
F_6 ( 1 ) ;
}
}
static inline void T_3 F_9 ( struct V_1 * V_1 )
{
T_1 V_12 ;
int V_13 , V_6 ;
V_12 = F_3 ( V_1 , V_14 ) ;
V_12 |= 0x60000000 ;
V_12 &= ~ 0x00ff0000 ;
V_12 &= ~ 0x18000000 ;
F_1 ( V_1 , V_14 , V_12 ) ;
F_1 ( V_1 , V_15 , 0x0000ffc0 ) ;
F_1 ( V_1 , V_10 ,
V_16 ) ;
F_1 ( V_1 , V_17 , 0xffffffff ) ;
F_1 ( V_1 , V_18 ,
V_19 ) ;
F_1 ( V_1 , V_17 , 0x00000400 ) ;
F_1 ( V_1 , V_20 , 0xffffffff ) ;
F_1 ( V_1 , V_21 , 0xffffffff ) ;
F_1 ( V_1 , V_22 , 0xffffffff ) ;
F_1 ( V_1 , V_23 , 0xffffffff ) ;
F_1 ( V_1 , V_24 , 0x80000000 ) ;
F_1 ( V_1 , V_25 ,
V_26 |
( V_27 << 4 ) |
( V_28 << 8 ) ) ;
F_1 ( V_1 , V_29 ,
V_30 ) ;
F_1 ( V_1 , V_10 , V_31 ) ;
V_13 = F_5 ( V_1 , 2 ) & 0xf ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
unsigned int V_32 ;
F_7 ( V_1 , 7 , V_6 ) ;
V_32 = F_5 ( V_1 , 8 ) ;
if ( V_32 & 0x20 )
F_7 ( V_1 , 8 , V_32 & ~ 1 ) ;
}
}
static inline void T_3 F_10 ( struct V_1 * V_1 )
{
int V_6 , V_33 ;
for ( V_6 = 0 ; V_6 < 9 ; V_6 ++ ) {
F_6 ( 200 ) ;
V_33 = F_3 ( V_1 , V_34 ) ;
if ( V_33 & V_35 )
F_1 ( V_1 , V_36 ,
V_35 ) ;
}
}
static inline void T_3 F_11 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_37 , 0xffffffff ) ;
F_1 ( V_1 , V_38 , 0xffffffff ) ;
F_1 ( V_1 , V_39 , 0xffff0000 ) ;
}
static inline void T_3 F_12 ( struct V_1 * V_1 )
{
F_8 ( V_1 ) ;
F_1 ( V_1 , V_10 , V_40 ) ;
F_1 ( V_1 , V_36 , 0xffffffff ) ;
F_1 ( V_1 , V_41 , 0xffffffff ) ;
F_6 ( 50 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
F_11 ( V_1 ) ;
}
static inline void T_3 F_13 ( int V_42 , int V_43 , int V_44 )
{
unsigned long V_45 ;
struct V_1 V_1 ;
F_14 ( V_46 L_1
L_2 , V_42 , V_43 , V_44 ) ;
V_45 = F_15 ( V_42 , V_43 , V_44 , V_47 + ( 0 << 2 ) )
& V_48 ;
F_16 ( V_49 , V_45 ) ;
V_1 . V_4 = ( void V_50 * ) F_17 ( V_49 ) ;
F_12 ( & V_1 ) ;
}
void T_3 F_18 ( void )
{
int V_42 , V_43 , V_44 ;
T_1 V_51 ;
if ( ! F_19 () )
return;
for ( V_42 = 0 ; V_42 < 32 ; V_42 ++ ) {
for ( V_43 = 0 ; V_43 < 32 ; V_43 ++ ) {
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
V_51 = F_15 ( V_42 , V_43 , V_44 ,
V_52 ) ;
if ( V_51 == 0xffffffff )
continue;
if ( V_51 >> 8 != V_53 )
continue;
F_13 ( V_42 , V_43 , V_44 ) ;
break;
}
}
}
F_14 ( V_46 L_3 ) ;
}
static int T_3 F_20 ( char * V_54 )
{
if ( ! strcmp ( V_54 , L_4 ) )
V_55 = 1 ;
return 0 ;
}
