static inline int F_1 ( int V_1 , int V_2 )
{
return ( V_1 * V_2 ) / 1024 ;
}
static inline int F_2 ( int V_3 , int V_2 )
{
return V_3 * V_2 / 256 ;
}
static inline int F_3 ( int V_4 , int V_2 )
{
return F_4 ( F_5 ( V_4 * 256 , V_2 ) , 0 , 255 ) ;
}
static inline int F_6 ( int V_1 , int V_5 )
{
return V_1 * 1400000 / ( V_5 * 255 ) ;
}
static int F_7 ( struct V_6 * V_7 , int V_8 )
{
int V_9 ;
V_9 = F_8 ( V_7 , V_8 ) ;
if ( F_9 ( V_9 < 0 ) )
return V_9 ;
return V_9 >> 6 ;
}
static struct V_10 * F_10 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = F_11 ( V_12 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
F_12 ( & V_13 -> V_14 ) ;
if ( F_13 ( V_15 , V_13 -> V_16 + V_17 ) || ! V_13 -> V_18 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_20 ; V_19 ++ )
V_13 -> V_1 [ V_19 ]
= F_7 ( V_7 , F_14 ( V_19 ) ) ;
if ( V_13 -> V_21 ) {
V_13 -> V_1 [ V_22 ]
= F_7 ( V_7 , V_23 ) ;
V_13 -> V_24
= F_15 ( V_7 ,
V_25 ) ;
}
for ( V_19 = 0 ; V_19 < F_16 ( V_13 -> V_20 , 8 ) ; V_19 ++ )
V_13 -> V_26 [ V_19 ]
= F_15 ( V_7 , F_17 ( V_19 ) ) ;
V_13 -> V_16 = V_15 ;
V_13 -> V_18 = 1 ;
}
F_18 ( & V_13 -> V_14 ) ;
return V_13 ;
}
static T_1 F_19 ( struct V_11 * V_12 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_30 * V_31 = F_20 ( V_28 ) ;
struct V_10 * V_13 = F_10 ( V_12 ) ;
int V_32 = V_13 -> V_26 [ V_31 -> V_33 ] ;
if ( V_32 < 0 )
return V_32 ;
V_32 &= ( 1 << V_31 -> V_34 ) ;
if ( V_32 )
F_21 ( V_13 -> V_7 ,
F_17 ( V_31 -> V_33 ) , V_32 ) ;
return snprintf ( V_29 , V_35 , L_1 , ! ! V_32 ) ;
}
static T_1 F_22 ( struct V_11 * V_12 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_36 * V_37 = F_23 ( V_28 ) ;
struct V_10 * V_13 = F_10 ( V_12 ) ;
int V_1 = V_13 -> V_1 [ V_37 -> V_34 ] ;
if ( F_9 ( V_1 < 0 ) )
return V_1 ;
return snprintf ( V_29 , V_35 , L_1 ,
F_1 ( V_1 , V_13 -> V_2 [ V_37 -> V_34 ] ) ) ;
}
static T_1 F_24 ( struct V_11 * V_12 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_10 * V_13 = F_10 ( V_12 ) ;
if ( F_9 ( V_13 -> V_24 < 0 ) )
return V_13 -> V_24 ;
return snprintf ( V_29 , V_35 , L_1 ,
F_6 ( V_13 -> V_24 , V_13 -> V_38 ) ) ;
}
static T_1 F_25 ( struct V_11 * V_12 ,
struct V_27 * V_28 ,
const char * V_29 , T_2 V_39 )
{
struct V_30 * V_31 = F_20 ( V_28 ) ;
struct V_10 * V_13 = F_11 ( V_12 ) ;
unsigned long V_32 ;
int V_40 ;
int V_3 ;
V_40 = F_26 ( V_29 , 10 , & V_32 ) ;
if ( F_9 ( V_40 < 0 ) )
return V_40 ;
V_3 = F_3 ( V_32 , V_13 -> V_2 [ V_31 -> V_34 ] ) ;
F_12 ( & V_13 -> V_14 ) ;
V_13 -> V_3 [ V_31 -> V_33 ] [ V_31 -> V_34 ]
= F_2 ( V_3 , V_13 -> V_2 [ V_31 -> V_34 ] ) ;
F_21 ( V_13 -> V_7 ,
F_27 ( V_31 -> V_33 , V_31 -> V_34 ) ,
V_3 ) ;
F_18 ( & V_13 -> V_14 ) ;
return V_39 ;
}
static T_1 F_28 ( struct V_11 * V_12 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_30 * V_31 = F_20 ( V_28 ) ;
struct V_10 * V_13 = F_11 ( V_12 ) ;
return snprintf ( V_29 , V_35 , L_1 ,
V_13 -> V_3 [ V_31 -> V_33 ] [ V_31 -> V_34 ] ) ;
}
static T_3 F_29 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_11 * V_12 = F_30 ( V_42 , struct V_11 , V_42 ) ;
struct V_10 * V_13 = F_11 ( V_12 ) ;
int V_34 = V_45 / 4 ;
if ( V_34 >= V_13 -> V_20 || ! V_13 -> V_2 [ V_34 ] )
return 0 ;
return V_44 -> V_46 ;
}
static T_3 F_31 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_34 )
{
struct V_11 * V_12 = F_30 ( V_42 , struct V_11 , V_42 ) ;
struct V_10 * V_13 = F_11 ( V_12 ) ;
if ( V_34 >= V_13 -> V_20 )
return 0 ;
return V_44 -> V_46 ;
}
static int F_32 ( struct V_6 * V_7 ,
const struct V_47 * V_48 )
{
struct V_49 * V_50 = V_7 -> V_50 ;
struct V_10 * V_13 ;
struct V_11 * V_12 = & V_7 -> V_12 ;
struct V_11 * V_51 ;
int V_19 , V_52 , V_32 ;
bool V_53 ;
bool V_54 = false ;
int V_55 = 0 ;
if ( ! F_33 ( V_50 , V_56
| V_57 ) )
return - V_58 ;
V_13 = F_34 ( V_12 , sizeof( * V_13 ) , V_59 ) ;
if ( F_9 ( ! V_13 ) )
return - V_60 ;
V_13 -> V_7 = V_7 ;
F_35 ( & V_13 -> V_14 ) ;
V_13 -> V_20 = V_61 [ V_48 -> V_62 ] ;
V_13 -> V_21 = V_63 [ V_48 -> V_62 ] ;
V_53 = V_64 [ V_48 -> V_62 ] ;
if ( V_53 ) {
V_32 = F_15 ( V_7 , V_65 ) ;
if ( F_9 ( V_32 < 0 ) )
return V_32 ;
V_54 = V_32 & V_66 ;
}
for ( V_19 = 0 ; V_19 < F_16 ( V_13 -> V_20 , 4 ) ; V_19 ++ ) {
V_32 = F_15 ( V_7 , F_36 ( V_19 ) ) ;
if ( F_9 ( V_32 < 0 ) )
return V_32 ;
for ( V_52 = 0 ; V_52 < 4 && V_19 * 4 + V_52 < V_13 -> V_20 ; V_52 ++ ) {
V_13 -> V_2 [ V_19 * 4 + V_52 ] =
V_67 [ ( V_32 >> ( V_52 * 2 ) ) & 0x3 ] ;
}
}
for ( V_19 = 0 ; V_19 < V_68 ; V_19 ++ ) {
if ( V_19 == 0 && ! V_53 )
continue;
for ( V_52 = 0 ; V_52 < V_13 -> V_20 ; V_52 ++ ) {
V_32 = F_15 ( V_7 ,
F_27 ( V_19 , V_52 ) ) ;
if ( F_9 ( V_32 < 0 ) )
return V_32 ;
V_13 -> V_3 [ V_19 ] [ V_52 ] = F_2 ( V_32 , V_13 -> V_2 [ V_52 ] ) ;
}
}
V_13 -> V_55 [ V_55 ++ ] = & V_69 ;
if ( V_53 )
V_13 -> V_55 [ V_55 ++ ] = V_54 ?
& V_70 : & V_71 ;
if ( V_13 -> V_21 ) {
V_32 = F_15 ( V_7 , V_72 ) ;
if ( F_9 ( V_32 < 0 ) )
return V_32 ;
if ( V_32 & V_73 ) {
V_13 -> V_38 = 6 << ( ( V_32 >> 2 ) & 0x03 ) ;
V_13 -> V_2 [ V_22 ]
= V_74 [ ( V_32 >> 1 ) & 0x01 ] ;
V_13 -> V_55 [ V_55 ++ ] = & V_75 ;
} else {
V_13 -> V_21 = false ;
}
}
V_51 = F_37 ( V_12 , V_7 -> V_76 ,
V_13 , V_13 -> V_55 ) ;
if ( F_9 ( F_38 ( V_51 ) ) )
return F_39 ( V_51 ) ;
return 0 ;
}
