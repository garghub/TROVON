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
return ( ( V_9 & 0xff ) << 2 ) | ( ( V_9 >> 14 ) & 0x03 ) ;
}
static struct V_10 * F_10 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_11 ( V_12 ) ;
struct V_10 * V_13 = F_12 ( V_7 ) ;
F_13 ( & V_13 -> V_14 ) ;
if ( F_14 ( V_15 , V_13 -> V_16 + V_17 ) || ! V_13 -> V_18 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_20 ; V_19 ++ )
V_13 -> V_1 [ V_19 ]
= F_7 ( V_7 , F_15 ( V_19 ) ) ;
if ( V_13 -> V_21 ) {
V_13 -> V_1 [ V_22 ]
= F_7 ( V_7 , V_23 ) ;
V_13 -> V_24
= F_16 ( V_7 ,
V_25 ) ;
}
for ( V_19 = 0 ; V_19 < F_17 ( V_13 -> V_20 , 8 ) ; V_19 ++ )
V_13 -> V_26 [ V_19 ]
= F_16 ( V_7 , F_18 ( V_19 ) ) ;
V_13 -> V_16 = V_15 ;
V_13 -> V_18 = 1 ;
}
F_19 ( & V_13 -> V_14 ) ;
return V_13 ;
}
static T_1 F_20 ( struct V_11 * V_12 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_30 * V_31 = F_21 ( V_28 ) ;
struct V_10 * V_13 = F_10 ( V_12 ) ;
int V_32 = V_13 -> V_26 [ V_31 -> V_33 ] ;
if ( V_32 < 0 )
return V_32 ;
V_32 &= ( 1 << V_31 -> V_34 ) ;
if ( V_32 )
F_22 ( F_11 ( V_12 ) ,
F_18 ( V_31 -> V_33 ) , V_32 ) ;
return snprintf ( V_29 , V_35 , L_1 , ! ! V_32 ) ;
}
static T_1 F_23 ( struct V_11 * V_12 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_36 * V_37 = F_24 ( V_28 ) ;
struct V_10 * V_13 = F_10 ( V_12 ) ;
int V_1 = V_13 -> V_1 [ V_37 -> V_34 ] ;
if ( F_9 ( V_1 < 0 ) )
return V_1 ;
return snprintf ( V_29 , V_35 , L_1 ,
F_1 ( V_1 , V_13 -> V_2 [ V_37 -> V_34 ] ) ) ;
}
static T_1 F_25 ( struct V_11 * V_12 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_10 * V_13 = F_10 ( V_12 ) ;
if ( F_9 ( V_13 -> V_24 < 0 ) )
return V_13 -> V_24 ;
return snprintf ( V_29 , V_35 , L_1 ,
F_6 ( V_13 -> V_24 , V_13 -> V_38 ) ) ;
}
static T_1 F_26 ( struct V_11 * V_12 ,
struct V_27 * V_28 ,
const char * V_29 , T_2 V_39 )
{
struct V_30 * V_31 = F_21 ( V_28 ) ;
struct V_6 * V_7 = F_11 ( V_12 ) ;
struct V_10 * V_13 = F_12 ( V_7 ) ;
unsigned long V_32 ;
int V_40 ;
int V_3 ;
V_40 = F_27 ( V_29 , 10 , & V_32 ) ;
if ( F_9 ( V_40 < 0 ) )
return V_40 ;
V_3 = F_3 ( V_32 , V_13 -> V_2 [ V_31 -> V_34 ] ) ;
F_13 ( & V_13 -> V_14 ) ;
V_13 -> V_3 [ V_31 -> V_33 ] [ V_31 -> V_34 ]
= F_2 ( V_3 , V_13 -> V_2 [ V_31 -> V_34 ] ) ;
F_22 ( V_7 ,
F_28 ( V_31 -> V_33 , V_31 -> V_34 ) ,
V_3 ) ;
F_19 ( & V_13 -> V_14 ) ;
return V_39 ;
}
static T_1 F_29 ( struct V_11 * V_12 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_30 * V_31 = F_21 ( V_28 ) ;
struct V_6 * V_7 = F_11 ( V_12 ) ;
struct V_10 * V_13 = F_12 ( V_7 ) ;
return snprintf ( V_29 , V_35 , L_1 ,
V_13 -> V_3 [ V_31 -> V_33 ] [ V_31 -> V_34 ] ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
F_31 ( & V_7 -> V_12 . V_41 , & V_42 ) ;
F_31 ( & V_7 -> V_12 . V_41 , & V_43 ) ;
F_31 ( & V_7 -> V_12 . V_41 , & V_44 ) ;
F_31 ( & V_7 -> V_12 . V_41 , & V_45 ) ;
}
static int F_32 ( struct V_6 * V_7 ,
const struct V_46 * V_47 )
{
struct V_48 * V_49 = V_7 -> V_49 ;
struct V_10 * V_13 ;
int V_19 , V_50 , V_32 , V_51 ;
bool V_52 ;
bool V_53 = false ;
if ( ! F_33 ( V_49 , V_54
| V_55 ) )
return - V_56 ;
V_13 = F_34 ( sizeof( * V_13 ) , V_57 ) ;
if ( F_9 ( ! V_13 ) )
return - V_58 ;
F_35 ( V_7 , V_13 ) ;
F_36 ( & V_13 -> V_14 ) ;
V_13 -> V_20 = V_59 [ V_47 -> V_60 ] ;
V_13 -> V_21 = V_61 [ V_47 -> V_60 ] ;
V_52 = V_62 [ V_47 -> V_60 ] ;
if ( V_52 ) {
V_32 = F_16 ( V_7 , V_63 ) ;
if ( F_9 ( V_32 < 0 ) ) {
V_51 = V_32 ;
goto V_64;
}
V_53 = V_32 & V_65 ;
}
for ( V_19 = 0 ; V_19 < F_17 ( V_13 -> V_20 , 4 ) ; V_19 ++ ) {
V_32 = F_16 ( V_7 , F_37 ( V_19 ) ) ;
if ( F_9 ( V_32 < 0 ) ) {
V_51 = V_32 ;
goto V_64;
}
for ( V_50 = 0 ; V_50 < 4 && V_19 * 4 + V_50 < V_13 -> V_20 ; V_50 ++ ) {
V_13 -> V_2 [ V_19 * 4 + V_50 ] =
V_66 [ ( V_32 >> ( V_50 * 2 ) ) & 0x3 ] ;
}
}
for ( V_19 = 0 ; V_19 < V_67 ; V_19 ++ ) {
if ( V_19 == 0 && ! V_52 )
continue;
for ( V_50 = 0 ; V_50 < V_13 -> V_20 ; V_50 ++ ) {
V_32 = F_16 ( V_7 ,
F_28 ( V_19 , V_50 ) ) ;
if ( F_9 ( V_32 < 0 ) ) {
V_51 = V_32 ;
goto V_64;
}
V_13 -> V_3 [ V_19 ] [ V_50 ] = F_2 ( V_32 , V_13 -> V_2 [ V_50 ] ) ;
}
}
for ( V_19 = 0 ; V_19 < V_13 -> V_20 * 4 ; V_19 ++ ) {
if ( ! V_13 -> V_2 [ V_19 / 4 ] )
continue;
V_51 = F_38 ( & V_7 -> V_12 . V_41 ,
V_68 [ V_19 ] ) ;
if ( F_9 ( V_51 ) )
goto V_69;
}
if ( V_52 ) {
struct V_70 * * V_37 = V_53 ?
V_71 : V_72 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_20 ; V_19 ++ ) {
if ( ! V_13 -> V_2 [ V_19 ] )
continue;
V_51 = F_38 ( & V_7 -> V_12 . V_41 , V_37 [ V_19 ] ) ;
if ( F_9 ( V_51 ) )
goto V_69;
}
}
if ( V_13 -> V_21 ) {
V_32 = F_16 ( V_7 , V_73 ) ;
if ( F_9 ( V_32 < 0 ) ) {
V_51 = V_32 ;
goto V_69;
}
if ( V_32 & V_74 ) {
V_13 -> V_38 = 6 << ( ( V_32 >> 2 ) & 0x03 ) ;
V_13 -> V_2 [ V_22 ]
= V_75 [ ( V_32 >> 1 ) & 0x01 ] ;
V_51 = F_39 ( & V_7 -> V_12 . V_41 ,
& V_44 ) ;
if ( F_9 ( V_51 ) )
goto V_69;
} else {
V_13 -> V_21 = false ;
}
}
V_13 -> V_76 = F_40 ( & V_7 -> V_12 ) ;
if ( F_9 ( F_41 ( V_13 -> V_76 ) ) ) {
V_51 = F_42 ( V_13 -> V_76 ) ;
goto V_69;
}
return 0 ;
V_69:
F_30 ( V_7 ) ;
V_64:
F_43 ( V_13 ) ;
return V_51 ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_10 * V_13 = F_12 ( V_7 ) ;
F_45 ( V_13 -> V_76 ) ;
F_30 ( V_7 ) ;
F_43 ( V_13 ) ;
return 0 ;
}
static int T_3 F_46 ( void )
{
return F_47 ( & V_77 ) ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_77 ) ;
}
