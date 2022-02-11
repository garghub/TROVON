static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
F_2 ( V_2 , 1 , L_1 ) ;
if ( V_2 -> V_5 &&
F_3 ( 100 ) < V_2 -> V_5 )
return;
F_4 ( & V_2 -> V_6 ) ;
if ( ! F_5 ( & V_2 -> V_7 ) ) {
V_4 = F_6 ( V_2 -> V_7 . V_8 ,
struct V_3 , V_9 ) ;
F_7 ( & V_4 -> V_9 ) ;
}
F_8 ( & V_2 -> V_6 ) ;
if ( V_4 ) {
V_4 -> V_10 . V_11 . V_12 = V_2 -> V_13 ;
F_9 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_10 . V_11 . V_14 ) ;
V_4 -> V_10 . V_11 . V_14 . V_15 += V_2 -> V_16 ;
F_11 ( & V_4 -> V_10 , V_2 -> V_17 ?
V_18 : V_19 ) ;
V_2 -> V_17 = false ;
}
}
static int F_12 ( void * V_20 )
{
struct V_1 * V_2 = V_20 ;
T_1 V_21 ;
T_1 V_22 ;
T_1 V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
unsigned V_26 ;
F_2 ( V_2 , 1 , L_2 ) ;
F_13 () ;
V_2 -> V_27 = 0 ;
if ( V_2 -> V_28 )
V_2 -> V_27 = 0xffffff80U ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = false ;
for (; ; ) {
F_14 () ;
if ( F_15 () )
break;
F_16 ( & V_2 -> V_32 ) ;
V_25 = V_30 ;
if ( V_2 -> V_31 ) {
V_2 -> V_29 = V_25 ;
V_2 -> V_27 = V_2 -> V_13 + 1 ;
V_2 -> V_13 = 0 ;
V_2 -> V_31 = false ;
}
V_24 = V_25 - V_2 -> V_29 ;
V_22 = ( T_1 ) V_24 * V_2 -> V_33 +
( V_34 * V_35 ) / 2 ;
F_17 ( V_22 , V_34 * V_35 ) ;
if ( V_24 > V_36 ) {
V_2 -> V_29 = V_25 ;
V_2 -> V_27 = V_22 ;
V_22 = 0 ;
}
V_2 -> V_13 = V_22 + V_2 -> V_27 ;
F_1 ( V_2 ) ;
F_18 ( & V_2 -> V_32 ) ;
V_21 = V_22 * V_35 ;
V_24 = V_30 - V_2 -> V_29 ;
V_21 += V_35 ;
V_23 = V_21 * V_34 +
V_2 -> V_33 / 2 ;
F_17 ( V_23 , V_2 -> V_33 ) ;
if ( V_23 < V_24 )
V_23 = V_24 ;
V_26 = V_23 - V_24 ;
F_19 ( V_26 ? V_26 : 1 ) ;
}
F_2 ( V_2 , 1 , L_3 ) ;
return 0 ;
}
static int F_20 ( struct V_37 * V_38 , const struct V_39 * V_40 ,
unsigned * V_41 , unsigned * V_42 ,
unsigned V_43 [] , void * V_44 [] )
{
V_43 [ 0 ] = V_35 * 2 ;
* V_42 = 1 ;
return 0 ;
}
static int F_21 ( struct V_45 * V_10 )
{
struct V_1 * V_2 = F_22 ( V_10 -> V_37 ) ;
unsigned V_46 = V_35 * 2 ;
F_2 ( V_2 , 1 , L_4 , V_47 ) ;
if ( V_2 -> V_48 ) {
V_2 -> V_48 = false ;
return - V_49 ;
}
if ( F_23 ( V_10 , 0 ) < V_46 ) {
F_2 ( V_2 , 1 , L_5 ,
V_47 , F_23 ( V_10 , 0 ) , V_46 ) ;
return - V_49 ;
}
F_24 ( V_10 , 0 , V_46 ) ;
return 0 ;
}
static void F_25 ( struct V_45 * V_10 )
{
struct V_1 * V_2 = F_22 ( V_10 -> V_37 ) ;
struct V_3 * V_50 = F_26 ( V_10 , struct V_3 , V_10 ) ;
F_2 ( V_2 , 1 , L_4 , V_47 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_27 ( & V_50 -> V_9 , & V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_6 ) ;
}
static int F_28 ( struct V_37 * V_38 , unsigned V_51 )
{
struct V_1 * V_2 = F_22 ( V_38 ) ;
int V_52 = 0 ;
F_2 ( V_2 , 1 , L_4 , V_47 ) ;
V_2 -> V_13 = 0 ;
if ( V_2 -> V_53 ) {
V_2 -> V_53 = false ;
V_52 = - V_49 ;
} else if ( V_2 -> V_54 == NULL ) {
V_2 -> V_54 = F_29 ( F_12 , V_2 ,
L_6 , V_2 -> V_55 . V_56 ) ;
if ( F_30 ( V_2 -> V_54 ) ) {
F_31 ( & V_2 -> V_55 , L_7 ) ;
V_52 = F_32 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
}
}
if ( V_52 ) {
struct V_3 * V_50 , * V_57 ;
F_33 (buf, tmp, &dev->sdr_cap_active, list) {
F_7 ( & V_50 -> V_9 ) ;
F_11 ( & V_50 -> V_10 , V_58 ) ;
}
}
return V_52 ;
}
static void F_34 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_22 ( V_38 ) ;
if ( V_2 -> V_54 == NULL )
return;
while ( ! F_5 ( & V_2 -> V_7 ) ) {
struct V_3 * V_50 ;
V_50 = F_6 ( V_2 -> V_7 . V_8 , struct V_3 , V_9 ) ;
F_7 ( & V_50 -> V_9 ) ;
F_11 ( & V_50 -> V_10 , V_18 ) ;
}
F_18 ( & V_2 -> V_32 ) ;
F_35 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
F_16 ( & V_2 -> V_32 ) ;
}
int F_36 ( struct V_59 * V_59 , void * V_60 , struct V_61 * V_62 )
{
switch ( V_62 -> V_63 ) {
case 0 :
if ( V_62 -> V_64 >= F_37 ( V_65 ) )
return - V_49 ;
* V_62 = V_65 [ V_62 -> V_64 ] ;
return 0 ;
case 1 :
if ( V_62 -> V_64 >= F_37 ( V_66 ) )
return - V_49 ;
* V_62 = V_66 [ V_62 -> V_64 ] ;
return 0 ;
default:
return - V_49 ;
}
}
int F_38 ( struct V_59 * V_59 , void * V_60 , struct V_67 * V_68 )
{
struct V_1 * V_2 = F_39 ( V_59 ) ;
switch ( V_68 -> V_63 ) {
case 0 :
V_68 -> V_69 = V_2 -> V_33 ;
V_68 -> type = V_70 ;
return 0 ;
case 1 :
V_68 -> V_69 = V_2 -> V_71 ;
V_68 -> type = V_72 ;
return 0 ;
default:
return - V_49 ;
}
}
int F_40 ( struct V_59 * V_59 , void * V_60 , const struct V_67 * V_68 )
{
struct V_1 * V_2 = F_39 ( V_59 ) ;
unsigned V_73 = V_68 -> V_69 ;
unsigned V_62 ;
switch ( V_68 -> V_63 ) {
case 0 :
if ( V_68 -> type != V_70 )
return - V_49 ;
if ( V_73 < V_74 )
V_62 = 0 ;
else if ( V_73 < V_75 )
V_62 = 1 ;
else
V_62 = 2 ;
V_73 = F_41 ( unsigned , V_73 ,
V_65 [ V_62 ] . V_76 ,
V_65 [ V_62 ] . V_77 ) ;
if ( F_42 ( & V_2 -> V_78 ) &&
V_73 != V_2 -> V_33 ) {
V_2 -> V_31 = true ;
}
V_2 -> V_33 = V_73 ;
return 0 ;
case 1 :
if ( V_68 -> type != V_72 )
return - V_49 ;
V_2 -> V_71 = F_41 ( unsigned , V_73 ,
V_66 [ 0 ] . V_76 ,
V_66 [ 0 ] . V_77 ) ;
return 0 ;
default:
return - V_49 ;
}
}
int F_43 ( struct V_59 * V_59 , void * V_60 , struct V_79 * V_80 )
{
switch ( V_80 -> V_64 ) {
case 0 :
F_44 ( V_80 -> V_56 , L_8 , sizeof( V_80 -> V_56 ) ) ;
V_80 -> type = V_70 ;
V_80 -> V_81 = V_82 | V_83 ;
V_80 -> V_76 = V_65 [ 0 ] . V_76 ;
V_80 -> V_77 = V_65 [ 2 ] . V_77 ;
return 0 ;
case 1 :
F_44 ( V_80 -> V_56 , L_9 , sizeof( V_80 -> V_56 ) ) ;
V_80 -> type = V_72 ;
V_80 -> V_81 = V_82 | V_83 ;
V_80 -> V_76 = V_66 [ 0 ] . V_76 ;
V_80 -> V_77 = V_66 [ 0 ] . V_77 ;
return 0 ;
default:
return - V_49 ;
}
}
int F_45 ( struct V_59 * V_59 , void * V_60 , const struct V_79 * V_80 )
{
if ( V_80 -> V_64 > 1 )
return - V_49 ;
return 0 ;
}
int F_46 ( struct V_59 * V_59 , void * V_60 , struct V_84 * V_85 )
{
if ( V_85 -> V_64 )
return - V_49 ;
V_85 -> V_86 = V_87 ;
F_44 ( V_85 -> V_88 , L_10 , sizeof( V_85 -> V_88 ) ) ;
return 0 ;
}
int F_47 ( struct V_59 * V_59 , void * V_60 , struct V_39 * V_85 )
{
V_85 -> V_40 . V_89 . V_86 = V_87 ;
V_85 -> V_40 . V_89 . V_90 = V_35 * 2 ;
memset ( V_85 -> V_40 . V_89 . V_91 , 0 , sizeof( V_85 -> V_40 . V_89 . V_91 ) ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_50 )
{
T_2 * V_92 = F_48 ( & V_50 -> V_10 , 0 ) ;
unsigned long V_93 ;
unsigned long V_94 = F_23 ( & V_50 -> V_10 , 0 ) ;
T_3 V_95 ;
T_3 V_96 ;
T_3 V_97 ;
T_3 V_98 ;
#define F_49 1000
V_95 = F_50 ( V_99 * F_49 ,
V_2 -> V_33 ) ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 += 2 ) {
V_96 = F_51 ( V_2 -> V_100 ,
V_99 ) >> ( 31 - V_101 ) ;
V_2 -> V_100 += V_95 ;
V_2 -> V_102 += V_96 / 4 ;
while ( V_2 -> V_102 < V_99 )
V_2 -> V_102 += V_99 ;
while ( V_2 -> V_102 > V_99 )
V_2 -> V_102 -= V_99 ;
while ( V_2 -> V_100 > V_99 )
V_2 -> V_100 -= V_99 ;
V_97 = F_51 ( V_2 -> V_102 , V_99 ) ;
V_98 = F_52 ( V_2 -> V_102 , V_99 ) ;
V_97 >>= ( 31 - V_101 ) ;
V_98 >>= ( 31 - V_101 ) ;
V_97 = V_97 * 1275 + V_103 * 1275 ;
V_98 = V_98 * 1275 + V_103 * 1275 ;
* V_92 ++ = F_50 ( V_97 , V_103 * 10 ) ;
* V_92 ++ = F_50 ( V_98 , V_103 * 10 ) ;
}
}
