static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
unsigned int V_4 ;
T_1 V_5 ;
V_3 = V_2 -> V_3 * F_2 ( V_2 -> V_6 ) ;
F_3 ( V_3 , V_7 ) ;
V_5 = F_4 ( V_2 -> V_8 + V_9 ) ;
V_5 &= ~ V_10 ;
V_5 |= F_5 ( V_3 ) ;
F_6 ( V_5 , V_2 -> V_8 + V_9 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 -> V_12 ; V_4 ++ ) {
const struct V_13 * V_14 = & V_2 -> V_11 -> V_15 [ V_4 ] . V_14 ;
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_8 + V_14 -> V_16 ) ;
V_5 &= ~ ( V_14 -> V_17 << V_14 -> V_18 ) ;
V_5 |= ( V_14 -> V_19 & V_14 -> V_17 ) << V_14 -> V_18 ;
F_6 ( V_5 , V_2 -> V_8 + V_14 -> V_16 ) ;
}
return 0 ;
}
void F_7 ( struct V_1 * V_2 , unsigned long V_20 )
{
unsigned int V_4 ;
struct V_21 * V_22 = NULL ;
for ( V_4 = 0 ; V_4 < V_2 -> V_23 ; V_4 ++ ) {
if ( V_2 -> V_24 [ V_4 ] . V_20 == V_20 ) {
V_22 = & V_2 -> V_24 [ V_4 ] ;
break;
}
}
if ( ! V_22 ) {
F_8 ( V_2 -> V_25 , L_1 ,
V_20 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_11 -> V_26 ; ++ V_4 )
F_9 ( V_2 , V_22 -> V_27 [ V_4 ] , V_2 -> V_11 -> V_28 [ V_4 ] ) ;
}
unsigned int F_10 ( struct V_1 * V_2 )
{
T_2 V_29 ;
V_29 = F_11 ( V_2 , V_30 ) ;
V_29 &= V_31 ;
V_29 ++ ;
return V_29 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_32 * V_33 )
{
int V_34 ;
T_1 V_35 ;
V_34 = F_13 ( V_33 , L_2 , & V_35 ) ;
if ( V_34 ) {
F_8 ( V_2 -> V_25 ,
L_3 , V_33 -> V_36 ) ;
return V_34 ;
}
V_22 -> V_20 = V_35 ;
V_22 -> V_27 = F_14 ( V_2 -> V_25 , V_2 -> V_11 -> V_26 ,
sizeof( T_1 ) , V_37 ) ;
if ( ! V_22 -> V_27 )
return - V_38 ;
V_34 = F_15 ( V_33 , L_4 ,
V_22 -> V_27 ,
V_2 -> V_11 -> V_26 ) ;
if ( V_34 ) {
F_8 ( V_2 -> V_25 ,
L_5 ,
V_33 -> V_36 ) ;
return V_34 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_32 * V_39 ;
struct V_21 * V_22 ;
int V_40 = F_17 ( V_33 ) ;
int V_4 = 0 , V_34 ;
V_2 -> V_24 = F_14 ( V_2 -> V_25 , V_40 , sizeof( * V_22 ) ,
V_37 ) ;
if ( ! V_2 -> V_24 )
return - V_38 ;
V_2 -> V_23 = V_40 ;
F_18 (node, child) {
V_22 = & V_2 -> V_24 [ V_4 ++ ] ;
V_34 = F_12 ( V_2 , V_22 , V_39 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
T_1 V_41 , V_42 ;
int V_34 ;
V_41 = F_20 () ;
V_2 -> V_23 = 0 ;
F_18 (mc->dev->of_node, node) {
V_34 = F_13 ( V_33 , L_6 ,
& V_42 ) ;
if ( V_34 || ( V_42 != V_41 ) ) {
F_21 ( V_33 ) ;
continue;
}
V_34 = F_16 ( V_2 , V_33 ) ;
if ( V_34 )
return V_34 ;
F_21 ( V_33 ) ;
break;
}
if ( V_2 -> V_23 == 0 )
F_22 ( V_2 -> V_25 ,
L_7 ,
V_41 ) ;
return 0 ;
}
static T_3 F_23 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
unsigned long V_45 , V_17 ;
unsigned int V_46 ;
V_45 = F_11 ( V_2 , V_47 ) ;
V_17 = F_11 ( V_2 , V_48 ) ;
F_24 (bit, &status, 32 ) {
const char * error = V_49 [ V_46 ] ? : L_8 ;
const char * V_50 = L_8 , * V_51 ;
const char * V_52 , * V_53 ;
T_4 V_54 = 0 ;
unsigned int V_4 ;
char V_55 [ 7 ] ;
T_2 V_56 , type ;
T_1 V_5 ;
V_5 = F_11 ( V_2 , V_57 ) ;
#ifdef F_25
if ( V_2 -> V_11 -> V_58 > 32 ) {
V_54 = ( ( V_5 >> V_59 ) &
V_60 ) ;
V_54 <<= 32 ;
}
#endif
if ( V_5 & V_61 )
V_52 = L_9 ;
else
V_52 = L_10 ;
if ( V_5 & V_62 )
V_53 = L_11 ;
else
V_53 = L_12 ;
V_56 = V_5 & V_2 -> V_11 -> V_63 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 -> V_12 ; V_4 ++ ) {
if ( V_2 -> V_11 -> V_15 [ V_4 ] . V_56 == V_56 ) {
V_50 = V_2 -> V_11 -> V_15 [ V_4 ] . V_36 ;
break;
}
}
type = ( V_5 & V_64 ) >>
V_65 ;
V_51 = V_66 [ type ] ;
switch ( V_5 & V_64 ) {
case V_67 :
V_55 [ 0 ] = ' ' ;
V_55 [ 1 ] = '[' ;
if ( V_5 & V_68 )
V_55 [ 2 ] = 'R' ;
else
V_55 [ 2 ] = '-' ;
if ( V_5 & V_69 )
V_55 [ 3 ] = 'W' ;
else
V_55 [ 3 ] = '-' ;
if ( V_5 & V_70 )
V_55 [ 4 ] = '-' ;
else
V_55 [ 4 ] = 'S' ;
V_55 [ 5 ] = ']' ;
V_55 [ 6 ] = '\0' ;
break;
default:
V_55 [ 0 ] = '\0' ;
break;
}
V_5 = F_11 ( V_2 , V_71 ) ;
V_54 |= V_5 ;
F_26 ( V_2 -> V_25 , L_13 ,
V_50 , V_53 , V_52 , & V_54 , error ,
V_51 , V_55 ) ;
}
F_9 ( V_2 , V_45 , V_47 ) ;
return V_72 ;
}
static int F_27 ( struct V_73 * V_74 )
{
const struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_1 * V_2 ;
T_1 V_5 ;
int V_34 ;
V_76 = F_28 ( V_79 , V_74 -> V_25 . V_80 ) ;
if ( ! V_76 )
return - V_81 ;
V_2 = F_29 ( & V_74 -> V_25 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
F_30 ( V_74 , V_2 ) ;
V_2 -> V_11 = V_76 -> V_44 ;
V_2 -> V_25 = & V_74 -> V_25 ;
V_2 -> V_3 = 30 ;
V_78 = F_31 ( V_74 , V_82 , 0 ) ;
V_2 -> V_8 = F_32 ( & V_74 -> V_25 , V_78 ) ;
if ( F_33 ( V_2 -> V_8 ) )
return F_34 ( V_2 -> V_8 ) ;
V_2 -> V_6 = F_35 ( & V_74 -> V_25 , L_14 ) ;
if ( F_33 ( V_2 -> V_6 ) ) {
F_8 ( & V_74 -> V_25 , L_15 ,
F_34 ( V_2 -> V_6 ) ) ;
return F_34 ( V_2 -> V_6 ) ;
}
V_34 = F_1 ( V_2 ) ;
if ( V_34 < 0 ) {
F_8 ( & V_74 -> V_25 , L_16 ,
V_34 ) ;
return V_34 ;
}
V_34 = F_19 ( V_2 ) ;
if ( V_34 < 0 ) {
F_8 ( & V_74 -> V_25 , L_17 , V_34 ) ;
return V_34 ;
}
if ( F_36 ( V_83 ) ) {
V_2 -> V_84 = F_37 ( & V_74 -> V_25 , V_2 -> V_11 -> V_84 , V_2 ) ;
if ( F_33 ( V_2 -> V_84 ) ) {
F_8 ( & V_74 -> V_25 , L_18 ,
F_34 ( V_2 -> V_84 ) ) ;
return F_34 ( V_2 -> V_84 ) ;
}
}
V_2 -> V_43 = F_38 ( V_74 , 0 ) ;
if ( V_2 -> V_43 < 0 ) {
F_8 ( & V_74 -> V_25 , L_19 ) ;
return V_2 -> V_43 ;
}
V_34 = F_39 ( & V_74 -> V_25 , V_2 -> V_43 , F_23 , V_85 ,
F_40 ( & V_74 -> V_25 ) , V_2 ) ;
if ( V_34 < 0 ) {
F_8 ( & V_74 -> V_25 , L_20 , V_2 -> V_43 ,
V_34 ) ;
return V_34 ;
}
F_41 ( ! V_2 -> V_11 -> V_63 , L_21 ) ;
V_5 = V_86 | V_87 | V_88 |
V_89 | V_90 |
V_91 | V_92 ;
F_9 ( V_2 , V_5 , V_48 ) ;
return 0 ;
}
static int F_42 ( void )
{
return F_43 ( & V_93 ) ;
}
