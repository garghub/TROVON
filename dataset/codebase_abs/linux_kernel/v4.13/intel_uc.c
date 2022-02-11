static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( & V_2 -> V_4 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
V_2 -> V_5 = V_6 ;
}
static int F_4 ( struct V_7 * V_8 )
{
int V_9 ;
T_1 V_10 ;
V_9 = F_5 ( V_8 ) ;
if ( V_9 ) {
F_6 ( L_1 , V_9 ) ;
return V_9 ;
}
V_10 = F_7 ( V_11 ) ;
F_8 ( ! ( V_10 & V_12 ) ,
L_2 ,
V_10 ) ;
return V_9 ;
}
void F_9 ( struct V_7 * V_8 )
{
if ( ! F_10 ( V_8 ) ) {
if ( V_13 . V_14 > 0 ||
V_13 . V_15 > 0 )
F_11 ( L_3 ) ;
V_13 . V_14 = 0 ;
V_13 . V_15 = 0 ;
return;
}
if ( V_13 . V_14 < 0 )
V_13 . V_14 = F_12 ( V_8 ) ;
if ( V_13 . V_14 ) {
if ( F_13 ( V_8 ) )
F_14 ( & V_8 -> V_16 ) ;
if ( F_15 ( & V_8 -> V_17 ) )
V_13 . V_14 = 0 ;
}
if ( ! V_13 . V_14 )
V_13 . V_15 = 0 ;
if ( V_13 . V_15 < 0 )
V_13 . V_15 = F_16 ( V_8 ) ;
}
static void F_17 ( struct V_18 * V_17 )
{
struct V_7 * V_8 = F_18 ( V_17 ) ;
F_19 ( V_19 , V_20 ) ;
}
void F_20 ( struct V_7 * V_8 )
{
struct V_18 * V_17 = & V_8 -> V_17 ;
F_21 ( & V_17 -> V_21 ) ;
F_22 ( & V_17 -> V_22 ) ;
V_17 -> V_23 = V_24 ;
V_17 -> V_25 = F_17 ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_26 * V_27 = V_8 -> V_28 . V_27 ;
struct V_3 * V_4 ;
const struct V_29 * V_30 = NULL ;
struct V_31 * V_32 ;
T_2 V_33 ;
int V_34 ;
if ( ! V_2 -> V_35 )
return;
V_2 -> V_5 = V_36 ;
F_24 ( L_4 ,
F_25 ( V_2 -> V_5 ) ) ;
V_34 = F_26 ( & V_30 , V_2 -> V_35 , & V_27 -> V_37 ) ;
if ( V_34 )
goto V_38;
if ( ! V_30 )
goto V_38;
F_24 ( L_5 ,
V_2 -> V_35 , V_30 ) ;
if ( V_30 -> V_33 < sizeof( struct V_31 ) ) {
F_27 ( L_6 ) ;
goto V_38;
}
V_32 = (struct V_31 * ) V_30 -> V_39 ;
V_2 -> V_40 = 0 ;
V_2 -> V_41 = ( V_32 -> V_42 - V_32 -> V_43 -
V_32 -> V_44 - V_32 -> V_45 ) * sizeof( T_1 ) ;
if ( V_2 -> V_41 != sizeof( struct V_31 ) ) {
F_27 ( L_7 ) ;
goto V_38;
}
V_2 -> V_46 = V_2 -> V_40 + V_2 -> V_41 ;
V_2 -> V_47 = ( V_32 -> V_48 - V_32 -> V_42 ) * sizeof( T_1 ) ;
if ( V_32 -> V_44 != V_49 ) {
F_27 ( L_8 ) ;
goto V_38;
}
V_2 -> V_50 = V_2 -> V_46 + V_2 -> V_47 ;
V_2 -> V_51 = V_32 -> V_44 * sizeof( T_1 ) ;
V_33 = V_2 -> V_41 + V_2 -> V_47 + V_2 -> V_51 ;
if ( V_30 -> V_33 < V_33 ) {
F_27 ( L_9 ) ;
goto V_38;
}
switch ( V_2 -> type ) {
case V_52 :
V_33 = V_2 -> V_41 + V_2 -> V_47 ;
if ( V_33 > F_28 ( V_8 ) ) {
F_6 ( L_10 ) ;
goto V_38;
}
V_2 -> V_53 = V_32 -> V_17 . V_54 >> 16 ;
V_2 -> V_55 = V_32 -> V_17 . V_54 & 0xFFFF ;
break;
case V_56 :
V_2 -> V_53 = V_32 -> V_16 . V_54 >> 16 ;
V_2 -> V_55 = V_32 -> V_16 . V_54 & 0xFFFF ;
break;
default:
F_6 ( L_11 , V_2 -> type ) ;
V_34 = - V_57 ;
goto V_38;
}
if ( V_2 -> V_58 == 0 && V_2 -> V_59 == 0 ) {
F_27 ( L_12 ,
F_29 ( V_2 -> type ) ) ;
} else if ( V_2 -> V_53 != V_2 -> V_58 ||
V_2 -> V_55 < V_2 -> V_59 ) {
F_27 ( L_13 ,
F_29 ( V_2 -> type ) ,
V_2 -> V_53 , V_2 -> V_55 ,
V_2 -> V_58 , V_2 -> V_59 ) ;
V_34 = - V_57 ;
goto V_38;
}
F_24 ( L_14 ,
V_2 -> V_53 , V_2 -> V_55 ,
V_2 -> V_58 , V_2 -> V_59 ) ;
V_4 = F_30 ( V_8 , V_30 -> V_39 , V_30 -> V_33 ) ;
if ( F_31 ( V_4 ) ) {
V_34 = F_32 ( V_4 ) ;
goto V_38;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_33 = V_30 -> V_33 ;
F_24 ( L_15 ,
V_2 -> V_4 ) ;
F_33 ( V_30 ) ;
V_2 -> V_5 = V_60 ;
return;
V_38:
F_34 ( L_16 ,
V_2 -> V_35 , V_34 ) ;
F_24 ( L_17 ,
V_34 , V_30 , V_2 -> V_4 ) ;
F_33 ( V_30 ) ;
V_2 -> V_5 = V_61 ;
}
void F_35 ( struct V_7 * V_8 )
{
F_23 ( V_8 , & V_8 -> V_16 . V_30 ) ;
F_23 ( V_8 , & V_8 -> V_17 . V_30 ) ;
}
void F_36 ( struct V_7 * V_8 )
{
F_1 ( & V_8 -> V_17 . V_30 ) ;
F_1 ( & V_8 -> V_16 . V_30 ) ;
}
static inline T_3 F_37 ( struct V_18 * V_17 , T_1 V_62 )
{
F_38 ( ! V_17 -> V_63 . V_64 ) ;
F_38 ( ! V_17 -> V_63 . V_65 ) ;
F_38 ( V_62 >= V_17 -> V_63 . V_65 ) ;
return F_39 ( V_17 -> V_63 . V_64 + 4 * V_62 ) ;
}
static void F_40 ( struct V_18 * V_17 )
{
struct V_7 * V_8 = F_18 ( V_17 ) ;
enum V_66 V_67 = 0 ;
unsigned int V_62 ;
V_17 -> V_63 . V_64 = F_41 ( F_42 ( 0 ) ) ;
V_17 -> V_63 . V_65 = V_68 - 1 ;
for ( V_62 = 0 ; V_62 < V_17 -> V_63 . V_65 ; V_62 ++ ) {
V_67 |= F_43 ( V_8 ,
F_37 ( V_17 , V_62 ) ,
V_69 | V_70 ) ;
}
V_17 -> V_63 . V_67 = V_67 ;
}
static void F_44 ( struct V_18 * V_17 )
{
if ( ! V_17 -> log . V_71 || V_13 . V_72 < 0 )
return;
if ( ! V_17 -> V_73 )
V_17 -> V_73 = F_45 ( V_17 -> log . V_71 -> V_4 ) ;
return;
}
static void F_46 ( struct V_18 * V_17 )
{
if ( V_17 -> V_73 )
F_3 ( V_17 -> V_73 ) ;
}
static int F_47 ( struct V_18 * V_17 )
{
struct V_7 * V_8 = F_18 ( V_17 ) ;
F_40 ( V_17 ) ;
if ( F_48 ( V_8 ) )
return F_49 ( V_17 ) ;
V_17 -> V_23 = V_74 ;
return 0 ;
}
static void F_50 ( struct V_18 * V_17 )
{
struct V_7 * V_8 = F_18 ( V_17 ) ;
if ( F_48 ( V_8 ) )
F_51 ( V_17 ) ;
V_17 -> V_23 = V_24 ;
}
int F_52 ( struct V_7 * V_8 )
{
struct V_18 * V_17 = & V_8 -> V_17 ;
int V_9 , V_75 ;
if ( ! V_13 . V_14 )
return 0 ;
F_50 ( V_17 ) ;
F_53 ( V_8 ) ;
F_54 ( V_8 ) ;
if ( V_13 . V_15 ) {
V_9 = F_55 ( V_8 ) ;
if ( V_9 )
goto V_76;
}
F_19 ( V_77 , F_28 ( V_8 ) ) ;
F_19 ( V_78 ,
V_79 | V_80 ) ;
if ( F_56 ( V_8 ) )
V_75 = 3 ;
else
V_75 = 1 ;
while ( V_75 -- ) {
V_9 = F_4 ( V_8 ) ;
if ( V_9 )
goto V_81;
F_57 ( & V_8 -> V_16 ) ;
V_9 = F_58 ( & V_8 -> V_17 ) ;
if ( V_9 == 0 || V_9 != - V_82 )
break;
F_24 ( L_18
L_19 , V_9 , V_75 ) ;
}
if ( V_9 )
goto V_83;
V_9 = F_47 ( V_17 ) ;
if ( V_9 )
goto V_83;
F_59 ( V_8 ) ;
if ( V_13 . V_15 ) {
if ( V_13 . V_72 >= 0 )
F_60 ( V_8 ) ;
V_9 = F_61 ( V_8 ) ;
if ( V_9 )
goto V_84;
}
return 0 ;
V_84:
F_50 ( V_17 ) ;
F_62 ( V_8 ) ;
V_83:
F_44 ( V_17 ) ;
V_81:
if ( V_13 . V_15 )
F_63 ( V_8 ) ;
V_76:
F_64 ( V_8 ) ;
F_6 ( L_20 ) ;
if ( V_13 . V_14 > 1 || V_13 . V_15 > 1 )
V_9 = - V_85 ;
else
V_9 = 0 ;
if ( V_13 . V_15 ) {
V_13 . V_15 = 0 ;
F_27 ( L_21 ) ;
}
V_13 . V_14 = 0 ;
F_27 ( L_22 ) ;
return V_9 ;
}
void F_65 ( struct V_7 * V_8 )
{
F_46 ( & V_8 -> V_17 ) ;
if ( ! V_13 . V_14 )
return;
if ( V_13 . V_15 )
F_66 ( V_8 ) ;
F_50 ( & V_8 -> V_17 ) ;
if ( V_13 . V_15 ) {
F_62 ( V_8 ) ;
F_63 ( V_8 ) ;
}
F_64 ( V_8 ) ;
}
int V_24 ( struct V_18 * V_17 , const T_1 * V_86 , T_1 V_87 )
{
F_8 ( 1 , L_23 , * V_86 ) ;
return - V_88 ;
}
int V_74 ( struct V_18 * V_17 , const T_1 * V_86 , T_1 V_87 )
{
struct V_7 * V_8 = F_18 ( V_17 ) ;
T_1 V_89 ;
int V_62 ;
int V_9 ;
F_38 ( ! V_87 ) ;
F_38 ( V_87 > V_17 -> V_63 . V_65 ) ;
F_38 ( F_48 ( V_8 ) &&
* V_86 != V_90 &&
* V_86 != V_91 ) ;
F_67 ( & V_17 -> V_22 ) ;
F_68 ( V_8 , V_17 -> V_63 . V_67 ) ;
for ( V_62 = 0 ; V_62 < V_87 ; V_62 ++ )
F_19 ( F_37 ( V_17 , V_62 ) , V_86 [ V_62 ] ) ;
F_69 ( F_37 ( V_17 , V_62 - 1 ) ) ;
F_70 ( V_17 ) ;
V_9 = F_71 ( V_8 ,
F_37 ( V_17 , 0 ) ,
V_92 ,
V_92 ,
10 , 10 , & V_89 ) ;
if ( V_89 != V_93 ) {
if ( V_9 != - V_94 )
V_9 = - V_85 ;
F_34 ( L_24
L_25 ,
V_86 [ 0 ] , V_9 , V_89 , F_7 ( F_42 ( 15 ) ) ) ;
}
F_72 ( V_8 , V_17 -> V_63 . V_67 ) ;
F_73 ( & V_17 -> V_22 ) ;
return V_9 ;
}
int F_74 ( struct V_18 * V_17 )
{
struct V_7 * V_8 = F_18 ( V_17 ) ;
T_1 V_86 [ 2 ] ;
V_86 [ 0 ] = V_95 ;
if ( ! F_75 () || F_76 ( V_8 ) )
V_86 [ 1 ] = 0 ;
else
V_86 [ 1 ] = V_96 | V_97 ;
return F_77 ( V_17 , V_86 , F_78 ( V_86 ) ) ;
}
