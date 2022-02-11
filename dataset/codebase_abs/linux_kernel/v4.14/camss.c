inline void F_1 ( T_1 * V_1 )
{
* V_1 *= V_2 ;
* V_1 = F_2 ( * V_1 , V_3 ) ;
}
int F_3 ( int V_4 , struct V_5 * clock ,
struct V_6 * V_7 )
{
int V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_8 = F_4 ( clock [ V_9 ] . V_10 ) ;
if ( V_8 ) {
F_5 ( V_7 , L_1 , V_8 ) ;
goto error;
}
}
return 0 ;
error:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
F_6 ( clock [ V_9 ] . V_10 ) ;
return V_8 ;
}
void F_7 ( int V_4 , struct V_5 * clock )
{
int V_9 ;
for ( V_9 = V_4 - 1 ; V_9 >= 0 ; V_9 -- )
F_6 ( clock [ V_9 ] . V_10 ) ;
}
static struct V_11 * F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
while ( 1 ) {
V_14 = & V_12 -> V_15 [ 0 ] ;
if ( ! ( V_14 -> V_16 & V_17 ) )
return NULL ;
V_14 = F_9 ( V_14 ) ;
if ( ! V_14 || ! F_10 ( V_14 -> V_12 ) )
return NULL ;
V_12 = V_14 -> V_12 ;
if ( V_12 -> V_18 == V_19 )
return V_12 ;
}
}
int F_11 ( struct V_11 * V_12 , T_2 * V_20 )
{
struct V_11 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_21 = F_8 ( V_12 ) ;
if ( ! V_21 )
return - V_26 ;
V_23 = F_12 ( V_21 ) ;
V_25 = F_13 ( V_23 -> V_27 , V_28 ) ;
if ( ! V_25 )
return - V_29 ;
* V_20 = F_14 ( V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_39 * V_40 ;
struct V_41 V_42 = { { 0 } } ;
unsigned int V_9 ;
F_16 ( F_17 ( V_31 ) , & V_42 ) ;
V_33 -> V_36 . V_43 = V_42 . V_44 . V_45 ;
V_40 = & V_42 . V_46 . V_40 ;
V_35 -> V_10 . V_47 = V_40 -> V_48 ;
V_35 -> V_10 . V_49 = V_40 -> V_50 [ 0 ] ;
V_35 -> V_51 = V_40 -> V_52 ;
V_35 -> V_53 = F_18 ( V_7 , V_35 -> V_51 * sizeof( * V_35 -> V_53 ) ,
V_54 ) ;
if ( ! V_35 -> V_53 )
return - V_55 ;
for ( V_9 = 0 ; V_9 < V_35 -> V_51 ; V_9 ++ ) {
V_35 -> V_53 [ V_9 ] . V_47 = V_40 -> V_56 [ V_9 ] ;
V_35 -> V_53 [ V_9 ] . V_49 = V_40 -> V_50 [ V_9 + 1 ] ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_57 * V_58 )
{
struct V_30 * V_31 = NULL ;
struct V_30 * V_59 = NULL ;
unsigned int V_60 , V_9 ;
int V_8 ;
while ( ( V_31 = F_20 ( V_7 -> V_61 , V_31 ) ) )
if ( F_21 ( V_31 ) )
V_58 -> V_62 ++ ;
V_60 = sizeof( * V_58 -> V_63 ) * V_58 -> V_62 ;
V_58 -> V_63 = F_18 ( V_7 , V_60 , V_54 ) ;
if ( ! V_58 -> V_63 ) {
F_5 ( V_7 , L_2 ) ;
return - V_55 ;
}
V_9 = 0 ;
while ( ( V_31 = F_20 ( V_7 -> V_61 , V_31 ) ) ) {
struct V_32 * V_33 ;
if ( ! F_21 ( V_31 ) )
continue;
V_33 = F_18 ( V_7 , sizeof( * V_33 ) , V_54 ) ;
if ( ! V_33 ) {
F_22 ( V_31 ) ;
F_5 ( V_7 , L_2 ) ;
return - V_55 ;
}
V_58 -> V_63 [ V_9 ++ ] = & V_33 -> V_64 ;
V_8 = F_15 ( V_7 , V_31 , V_33 ) ;
if ( V_8 < 0 ) {
F_22 ( V_31 ) ;
return V_8 ;
}
V_59 = F_23 ( V_31 ) ;
F_22 ( V_31 ) ;
if ( ! V_59 ) {
F_5 ( V_7 , L_3 ) ;
return - V_29 ;
}
V_33 -> V_64 . V_65 = V_66 ;
V_33 -> V_64 . V_67 . V_68 . V_68 = F_17 ( V_59 ) ;
}
return V_58 -> V_62 ;
}
static int F_24 ( struct V_69 * V_69 )
{
unsigned int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_70 ) ; V_9 ++ ) {
V_8 = F_26 ( & V_69 -> V_70 [ V_9 ] ,
& V_71 [ V_9 ] , V_9 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 ,
L_4 ,
V_9 , V_8 ) ;
return V_8 ;
}
}
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_72 ) ; V_9 ++ ) {
V_8 = F_27 ( & V_69 -> V_72 [ V_9 ] ,
& V_73 [ V_9 ] , V_9 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 ,
L_5 ,
V_9 , V_8 ) ;
return V_8 ;
}
}
V_8 = F_28 ( & V_69 -> V_74 , & V_75 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 , L_6 ,
V_8 ) ;
return V_8 ;
}
V_8 = F_29 ( & V_69 -> V_76 , & V_77 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 , L_7 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_30 ( struct V_69 * V_69 )
{
int V_9 , V_78 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_70 ) ; V_9 ++ ) {
V_8 = F_31 ( & V_69 -> V_70 [ V_9 ] ,
& V_69 -> V_79 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 ,
L_8 ,
V_9 , V_8 ) ;
goto V_80;
}
}
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_72 ) ; V_9 ++ ) {
V_8 = F_32 ( & V_69 -> V_72 [ V_9 ] ,
& V_69 -> V_79 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 ,
L_9 ,
V_9 , V_8 ) ;
goto V_81;
}
}
V_8 = F_33 ( & V_69 -> V_74 , & V_69 -> V_79 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 , L_10 ,
V_8 ) ;
goto V_82;
}
V_8 = F_34 ( & V_69 -> V_76 , & V_69 -> V_79 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 , L_11 ,
V_8 ) ;
goto V_83;
}
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_70 ) ; V_9 ++ ) {
for ( V_78 = 0 ; V_78 < F_25 ( V_69 -> V_72 ) ; V_78 ++ ) {
V_8 = F_35 (
& V_69 -> V_70 [ V_9 ] . V_23 . V_12 ,
V_84 ,
& V_69 -> V_72 [ V_78 ] . V_23 . V_12 ,
V_85 ,
0 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 ,
L_12 ,
V_69 -> V_70 [ V_9 ] . V_23 . V_12 . V_86 ,
V_69 -> V_72 [ V_78 ] . V_23 . V_12 . V_86 ,
V_8 ) ;
goto V_87;
}
}
}
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_72 ) ; V_9 ++ ) {
for ( V_78 = 0 ; V_78 < F_25 ( V_69 -> V_74 . line ) ; V_78 ++ ) {
V_8 = F_35 (
& V_69 -> V_72 [ V_9 ] . V_23 . V_12 ,
V_88 ,
& V_69 -> V_74 . line [ V_78 ] . V_23 . V_12 ,
V_89 ,
0 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 ,
L_12 ,
V_69 -> V_72 [ V_9 ] . V_23 . V_12 . V_86 ,
V_69 -> V_74 . line [ V_78 ] . V_23 . V_12 . V_86 ,
V_8 ) ;
goto V_87;
}
}
}
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_74 . line ) ; V_9 ++ ) {
for ( V_78 = 0 ; V_78 < F_25 ( V_69 -> V_76 . line ) ; V_78 ++ ) {
V_8 = F_35 (
& V_69 -> V_74 . line [ V_9 ] . V_23 . V_12 ,
V_90 ,
& V_69 -> V_76 . line [ V_78 ] . V_23 . V_12 ,
V_91 ,
0 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 ,
L_12 ,
V_69 -> V_74 . line [ V_9 ] . V_23 . V_12 . V_86 ,
V_69 -> V_76 . line [ V_78 ] . V_23 . V_12 . V_86 ,
V_8 ) ;
goto V_87;
}
}
}
return 0 ;
V_87:
F_36 ( & V_69 -> V_76 ) ;
V_83:
F_37 ( & V_69 -> V_74 ) ;
V_82:
V_9 = F_25 ( V_69 -> V_72 ) ;
V_81:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
F_38 ( & V_69 -> V_72 [ V_9 ] ) ;
V_9 = F_25 ( V_69 -> V_70 ) ;
V_80:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
F_39 ( & V_69 -> V_70 [ V_9 ] ) ;
return V_8 ;
}
static void F_40 ( struct V_69 * V_69 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_70 ) ; V_9 ++ )
F_39 ( & V_69 -> V_70 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < F_25 ( V_69 -> V_72 ) ; V_9 ++ )
F_38 ( & V_69 -> V_72 [ V_9 ] ) ;
F_37 ( & V_69 -> V_74 ) ;
F_36 ( & V_69 -> V_76 ) ;
}
static int F_41 ( struct V_57 * V_92 ,
struct V_22 * V_23 ,
struct V_93 * V_64 )
{
struct V_69 * V_69 = F_42 ( V_92 , struct V_69 , V_58 ) ;
struct V_32 * V_33 =
F_42 ( V_64 , struct V_32 , V_64 ) ;
T_3 V_94 = V_33 -> V_36 . V_43 ;
struct V_95 * V_70 = & V_69 -> V_70 [ V_94 ] ;
V_70 -> V_96 . V_37 = & V_33 -> V_36 . V_37 ;
V_23 -> V_97 = V_70 ;
return 0 ;
}
static int F_43 ( struct V_57 * V_92 )
{
struct V_69 * V_69 = F_42 ( V_92 , struct V_69 , V_58 ) ;
struct V_98 * V_79 = & V_69 -> V_79 ;
struct V_22 * V_99 ;
int V_8 ;
F_44 (sd, &v4l2_dev->subdevs, list) {
if ( V_99 -> V_97 ) {
struct V_11 * V_21 = & V_99 -> V_12 ;
struct V_95 * V_70 =
(struct V_95 * ) V_99 -> V_97 ;
struct V_11 * V_100 = & V_70 -> V_23 . V_12 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_21 -> V_101 ; V_9 ++ ) {
if ( V_21 -> V_15 [ V_9 ] . V_16 & V_102 )
break;
}
if ( V_9 == V_21 -> V_101 ) {
F_5 ( V_69 -> V_7 ,
L_13 ) ;
return - V_29 ;
}
V_8 = F_35 ( V_21 , V_9 ,
V_100 , V_103 ,
V_104 | V_105 ) ;
if ( V_8 < 0 ) {
F_5 ( V_69 -> V_7 ,
L_12 ,
V_21 -> V_86 , V_100 -> V_86 , V_8 ) ;
return V_8 ;
}
}
}
V_8 = F_45 ( & V_69 -> V_79 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_46 ( & V_69 -> V_106 ) ;
}
static int F_47 ( struct V_107 * V_108 )
{
struct V_6 * V_7 = & V_108 -> V_7 ;
struct V_69 * V_69 ;
int V_8 ;
V_69 = F_48 ( sizeof( * V_69 ) , V_54 ) ;
if ( ! V_69 )
return - V_55 ;
F_49 ( & V_69 -> V_109 , 0 ) ;
V_69 -> V_7 = V_7 ;
F_50 ( V_108 , V_69 ) ;
V_8 = F_19 ( V_7 , & V_69 -> V_58 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_24 ( V_69 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_51 ( V_7 , 0xffffffff ) ;
if ( V_8 )
return V_8 ;
V_69 -> V_106 . V_7 = V_69 -> V_7 ;
F_52 ( V_69 -> V_106 . V_110 , L_14 ,
sizeof( V_69 -> V_106 . V_110 ) ) ;
V_69 -> V_106 . V_111 = & V_112 ;
F_53 ( & V_69 -> V_106 ) ;
V_69 -> V_79 . V_113 = & V_69 -> V_106 ;
V_8 = F_54 ( V_69 -> V_7 , & V_69 -> V_79 ) ;
if ( V_8 < 0 ) {
F_5 ( V_7 , L_15 , V_8 ) ;
return V_8 ;
}
V_8 = F_30 ( V_69 ) ;
if ( V_8 < 0 )
goto V_114;
if ( V_69 -> V_58 . V_62 ) {
V_69 -> V_58 . V_115 = F_41 ;
V_69 -> V_58 . V_116 = F_43 ;
V_8 = F_55 ( & V_69 -> V_79 ,
& V_69 -> V_58 ) ;
if ( V_8 ) {
F_5 ( V_7 ,
L_16 ,
V_8 ) ;
goto V_117;
}
} else {
V_8 = F_45 ( & V_69 -> V_79 ) ;
if ( V_8 < 0 ) {
F_5 ( V_7 , L_17 ,
V_8 ) ;
goto V_117;
}
V_8 = F_46 ( & V_69 -> V_106 ) ;
if ( V_8 < 0 ) {
F_5 ( V_7 , L_18 ,
V_8 ) ;
goto V_117;
}
}
return 0 ;
V_117:
F_40 ( V_69 ) ;
V_114:
F_56 ( & V_69 -> V_79 ) ;
return V_8 ;
}
void F_57 ( struct V_69 * V_69 )
{
F_56 ( & V_69 -> V_79 ) ;
F_58 ( & V_69 -> V_106 ) ;
F_59 ( & V_69 -> V_106 ) ;
F_60 ( V_69 ) ;
}
static int F_61 ( struct V_107 * V_108 )
{
struct V_69 * V_69 = F_62 ( V_108 ) ;
F_63 ( & V_69 -> V_76 ) ;
F_64 ( & V_69 -> V_58 ) ;
F_40 ( V_69 ) ;
if ( F_65 ( & V_69 -> V_109 ) == 0 )
F_57 ( V_69 ) ;
return 0 ;
}
