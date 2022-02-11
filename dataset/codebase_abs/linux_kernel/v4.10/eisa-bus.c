static int F_1 ( int * V_1 ,
int V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
V_8 = ( V_4 -> V_9 << 8 ) | V_6 -> V_10 ;
if ( V_1 [ V_7 ] == V_8 )
return 1 ;
}
return 0 ;
}
static void T_1 F_2 ( struct V_5 * V_6 )
{
#ifdef F_3
int V_7 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( ! strcmp ( V_6 -> V_12 . V_13 , V_14 [ V_7 ] . V_12 . V_13 ) ) {
F_4 ( V_6 -> V_15 ,
V_14 [ V_7 ] . V_16 ,
sizeof( V_6 -> V_15 ) ) ;
return;
}
}
sprintf ( V_6 -> V_15 , L_1 , V_6 -> V_12 . V_13 ) ;
#endif
}
static char T_1 * F_5 ( unsigned long V_17 )
{
static char V_18 [ V_19 ] ;
T_2 V_13 [ 4 ] ;
T_3 V_20 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
#ifdef F_6
F_7 ( 0x80 + V_7 , V_17 ) ;
#endif
V_13 [ V_7 ] = F_8 ( V_17 + V_7 ) ;
if ( ! V_7 && ( V_13 [ 0 ] & 0x80 ) )
return NULL ;
}
V_18 [ 0 ] = ( ( V_13 [ 0 ] >> 2 ) & 0x1f ) + ( 'A' - 1 ) ;
V_18 [ 1 ] = ( ( ( V_13 [ 0 ] & 3 ) << 3 ) | ( V_13 [ 1 ] >> 5 ) ) + ( 'A' - 1 ) ;
V_18 [ 2 ] = ( V_13 [ 1 ] & 0x1f ) + ( 'A' - 1 ) ;
V_20 = ( V_13 [ 2 ] << 8 ) | V_13 [ 3 ] ;
sprintf ( V_18 + 3 , L_2 , V_20 ) ;
return V_18 ;
}
static int F_9 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_5 * V_6 = F_10 ( V_22 ) ;
struct V_25 * V_26 = F_11 ( V_24 ) ;
const struct V_27 * V_28 = V_26 -> V_29 ;
if ( ! V_28 )
return 0 ;
while ( strlen ( V_28 -> V_13 ) ) {
if ( ! strcmp ( V_28 -> V_13 , V_6 -> V_12 . V_13 ) &&
V_6 -> V_30 & V_31 ) {
V_6 -> V_12 . V_32 = V_28 -> V_32 ;
return 1 ;
}
V_28 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_21 * V_22 , struct V_33 * V_34 )
{
struct V_5 * V_6 = F_10 ( V_22 ) ;
F_13 ( V_34 , L_3 V_35 , V_6 -> V_12 . V_13 ) ;
return 0 ;
}
int F_14 ( struct V_25 * V_26 )
{
V_26 -> V_36 . V_37 = & V_38 ;
return F_15 ( & V_26 -> V_36 ) ;
}
void F_16 ( struct V_25 * V_26 )
{
F_17 ( & V_26 -> V_36 ) ;
}
static T_4 F_18 ( struct V_21 * V_22 , struct V_39 * V_40 ,
char * V_41 )
{
struct V_5 * V_6 = F_10 ( V_22 ) ;
return sprintf ( V_41 , L_4 , V_6 -> V_12 . V_13 ) ;
}
static T_4 F_19 ( struct V_21 * V_22 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_5 * V_6 = F_10 ( V_22 ) ;
return sprintf ( V_41 , L_5 , V_6 -> V_30 & V_31 ) ;
}
static T_4 F_20 ( struct V_21 * V_22 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_5 * V_6 = F_10 ( V_22 ) ;
return sprintf ( V_41 , V_35 L_6 , V_6 -> V_12 . V_13 ) ;
}
static int T_1 F_21 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_10 )
{
char * V_13 ;
unsigned long V_42 ;
int V_7 ;
V_42 = F_22 ( V_4 , V_10 ) + V_43 ;
V_13 = F_5 ( V_42 ) ;
if ( ! V_13 )
return - 1 ;
memcpy ( V_6 -> V_12 . V_13 , V_13 , V_19 ) ;
V_6 -> V_10 = V_10 ;
V_6 -> V_30 = F_8 ( F_22 ( V_4 , V_10 ) + V_44 )
& V_31 ;
V_6 -> V_45 = F_22 ( V_4 , V_10 ) ;
V_6 -> V_46 = V_4 -> V_46 ;
F_2 ( V_6 ) ;
V_6 -> V_22 . V_47 = V_4 -> V_22 ;
V_6 -> V_22 . V_37 = & V_38 ;
V_6 -> V_22 . V_46 = & V_6 -> V_46 ;
V_6 -> V_22 . V_48 = V_6 -> V_46 ;
F_23 ( & V_6 -> V_22 , L_7 , V_4 -> V_9 , V_10 ) ;
for ( V_7 = 0 ; V_7 < V_49 ; V_7 ++ ) {
#ifdef F_3
V_6 -> V_50 [ V_7 ] . V_16 = V_6 -> V_15 ;
#else
V_6 -> V_50 [ V_7 ] . V_16 = V_6 -> V_12 . V_13 ;
#endif
}
if ( F_1 ( V_51 , V_52 , V_4 , V_6 ) )
V_6 -> V_30 = V_31 | V_53 ;
if ( F_1 ( V_54 , V_55 , V_4 , V_6 ) )
V_6 -> V_30 = V_53 ;
return 0 ;
}
static int T_1 F_24 ( struct V_5 * V_6 )
{
int V_56 = F_25 ( & V_6 -> V_22 ) ;
if ( V_56 ) {
F_26 ( & V_6 -> V_22 ) ;
return V_56 ;
}
V_56 = F_27 ( & V_6 -> V_22 , & V_57 ) ;
if ( V_56 )
goto V_58;
V_56 = F_27 ( & V_6 -> V_22 , & V_59 ) ;
if ( V_56 )
goto V_60;
V_56 = F_27 ( & V_6 -> V_22 , & V_61 ) ;
if ( V_56 )
goto V_62;
return 0 ;
V_62:
F_28 ( & V_6 -> V_22 , & V_59 ) ;
V_60:
F_28 ( & V_6 -> V_22 , & V_57 ) ;
V_58:
F_29 ( & V_6 -> V_22 ) ;
return V_56 ;
}
static int T_1 F_30 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_10 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_49 ; V_7 ++ ) {
if ( ! V_10 && V_7 > 0 ) {
V_6 -> V_50 [ V_7 ] . V_63 = V_6 -> V_50 [ V_7 ] . V_64 = 0 ;
continue;
}
if ( V_10 ) {
V_6 -> V_50 [ V_7 ] . V_16 = NULL ;
V_6 -> V_50 [ V_7 ] . V_63 = F_22 ( V_4 , V_10 )
+ ( V_7 * 0x400 ) ;
V_6 -> V_50 [ V_7 ] . V_64 = V_6 -> V_50 [ V_7 ] . V_63 + 0xff ;
V_6 -> V_50 [ V_7 ] . V_65 = V_66 ;
} else {
V_6 -> V_50 [ V_7 ] . V_16 = NULL ;
V_6 -> V_50 [ V_7 ] . V_63 = F_22 ( V_4 , V_10 )
+ V_43 ;
V_6 -> V_50 [ V_7 ] . V_64 = V_6 -> V_50 [ V_7 ] . V_63 + 3 ;
V_6 -> V_50 [ V_7 ] . V_65 = V_66 | V_67 ;
}
if ( F_31 ( V_4 -> V_50 , & V_6 -> V_50 [ V_7 ] ) )
goto V_68;
}
return 0 ;
V_68:
while ( -- V_7 >= 0 )
F_32 ( & V_6 -> V_50 [ V_7 ] ) ;
return - 1 ;
}
static void T_1 F_33 ( struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_49 ; V_7 ++ )
if ( V_6 -> V_50 [ V_7 ] . V_63 || V_6 -> V_50 [ V_7 ] . V_64 )
F_32 ( & V_6 -> V_50 [ V_7 ] ) ;
}
static int T_1 F_34 ( struct V_3 * V_4 )
{
int V_7 , V_69 ;
struct V_5 * V_6 ;
char * V_70 ;
F_35 ( V_4 -> V_22 , L_8 , V_4 -> V_9 ) ;
V_6 = F_36 ( sizeof( * V_6 ) , V_71 ) ;
if ( ! V_6 ) {
F_37 ( V_4 -> V_22 , L_9 ) ;
return - V_72 ;
}
if ( F_30 ( V_4 , V_6 , 0 ) ) {
F_38 ( V_4 -> V_22 ,
L_10 ) ;
F_39 ( V_6 ) ;
if ( ! V_4 -> V_73 )
return - V_74 ;
goto V_73;
}
if ( F_21 ( V_4 , V_6 , 0 ) ) {
F_33 ( V_6 ) ;
F_39 ( V_6 ) ;
if ( ! V_4 -> V_73 )
return - V_75 ;
goto V_73;
}
F_35 ( & V_6 -> V_22 , L_11 , V_6 -> V_12 . V_13 ) ;
if ( F_24 ( V_6 ) ) {
F_37 ( & V_6 -> V_22 , L_12 ,
V_6 -> V_12 . V_13 ) ;
F_33 ( V_6 ) ;
F_39 ( V_6 ) ;
}
V_73:
for ( V_69 = 0 , V_7 = 1 ; V_7 <= V_4 -> V_76 ; V_7 ++ ) {
V_6 = F_36 ( sizeof( * V_6 ) , V_71 ) ;
if ( ! V_6 ) {
F_37 ( V_4 -> V_22 , L_13 ,
V_7 ) ;
continue;
}
if ( F_30 ( V_4 , V_6 , V_7 ) ) {
F_38 ( V_4 -> V_22 ,
L_14 ,
V_7 ) ;
F_39 ( V_6 ) ;
continue;
}
if ( F_21 ( V_4 , V_6 , V_7 ) ) {
F_33 ( V_6 ) ;
F_39 ( V_6 ) ;
continue;
}
if ( V_6 -> V_30 == ( V_31 | V_53 ) )
V_70 = L_15 ;
else if ( V_6 -> V_30 == V_53 )
V_70 = L_16 ;
else if ( V_6 -> V_30 == 0 )
V_70 = L_17 ;
else
V_70 = L_18 ;
F_35 ( & V_6 -> V_22 , L_19 , V_7 ,
V_6 -> V_12 . V_13 , V_70 ) ;
V_69 ++ ;
if ( F_24 ( V_6 ) ) {
F_37 ( & V_6 -> V_22 , L_12 ,
V_6 -> V_12 . V_13 ) ;
F_33 ( V_6 ) ;
F_39 ( V_6 ) ;
}
}
F_35 ( V_4 -> V_22 , L_20 , V_69 , V_69 == 1 ? L_18 : L_21 ) ;
return 0 ;
}
int T_1 F_40 ( struct V_3 * V_4 )
{
int V_77 ;
V_4 -> V_78 . V_16 = V_78 . V_16 ;
V_4 -> V_78 . V_63 = V_4 -> V_50 -> V_63 ;
V_4 -> V_78 . V_64 = V_4 -> V_50 -> V_64 ;
V_4 -> V_78 . V_65 = V_67 ;
V_77 = F_31 ( & V_78 , & V_4 -> V_78 ) ;
if ( V_77 )
return V_77 ;
V_4 -> V_9 = V_79 ++ ;
V_77 = F_34 ( V_4 ) ;
if ( V_77 )
F_32 ( & V_4 -> V_78 ) ;
return V_77 ;
}
static int T_1 F_41 ( void )
{
int V_80 ;
V_80 = F_42 ( & V_38 ) ;
if ( V_80 )
return V_80 ;
F_43 ( V_81 L_22 ) ;
return 0 ;
}
