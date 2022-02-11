void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_4 ) ;
unsigned long V_5 ;
int V_6 ;
T_1 V_7 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
V_7 = V_3 -> V_10 ;
V_6 = V_3 -> V_11 ;
V_3 -> V_11 = F_5 ( V_3 -> V_12 ) ;
V_3 -> V_10 = F_6 ( V_3 -> V_12 ) ;
if ( V_6 == V_3 -> V_11 ) {
if ( ! V_3 -> V_11 )
F_4 ( & V_3 -> V_8 , V_5 ) ;
else {
if ( V_7 != V_3 -> V_10 ) {
V_3 -> V_13 -> V_14 . V_15 ++ ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_1 ) ;
F_8 ( & V_3 -> V_18 ) ;
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_2 ) ;
F_9 ( & V_3 -> V_18 ) ;
} else
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
} else if ( V_3 -> V_11 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 ( V_16 , V_3 -> V_13 -> V_17 , L_2 ) ;
F_9 ( & V_3 -> V_18 ) ;
} else {
V_3 -> V_13 -> V_14 . V_15 ++ ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 ( V_16 , V_3 -> V_13 -> V_17 , L_1 ) ;
F_8 ( & V_3 -> V_18 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_19 ) ;
struct V_20 * V_21 = V_3 -> V_13 ;
unsigned long V_5 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
while ( ( V_23 = F_11 ( & V_3 -> V_26 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_12 ( V_23 ) ;
return;
}
V_25 = (struct V_24 * ) V_23 ;
if ( V_3 -> V_27 != V_28 &&
V_3 -> V_27 != V_29 ) {
F_13 ( & V_3 -> V_26 , V_23 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_14 ( V_21 , V_25 ) ;
}
}
static inline int F_15 ( struct V_3 * V_3 , struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_30 * V_31 ;
struct V_32 * V_32 ;
struct V_33 * V_34 ;
V_31 = (struct V_30 * ) V_23 -> V_35 ;
if ( V_31 -> V_36 == F_16 ( V_37 ) ) {
memmove ( ( V_38 * ) V_31 + V_39 , V_31 , V_40 * 2 ) ;
V_31 = (struct V_30 * ) F_17 ( V_23 , V_39 ) ;
F_18 ( V_23 ) ;
}
if ( V_31 -> V_36 == F_16 ( V_41 ) ) {
F_17 ( V_23 , sizeof( * V_31 ) ) ;
F_19 ( & V_3 -> V_18 , V_23 ) ;
return 1 ;
}
if ( V_31 -> V_36 != F_16 ( V_42 ) )
goto V_43;
F_20 ( V_23 , sizeof( * V_31 ) ) ;
F_17 ( V_23 , sizeof( * V_31 ) ) ;
V_32 = (struct V_32 * ) V_23 -> V_35 ;
if ( F_21 ( V_32 ) != V_44 )
goto V_43;
V_25 = (struct V_24 * ) V_23 ;
F_22 ( V_25 ) ;
F_23 ( V_25 ) = V_32 -> V_45 ;
F_17 ( V_23 , sizeof( struct V_32 ) ) ;
F_24 ( V_23 ) ;
V_34 = (struct V_33 * ) ( V_23 -> V_35 + V_23 -> V_46 - sizeof( * V_34 ) ) ;
F_25 ( V_25 ) = V_34 -> V_47 ;
F_26 ( V_23 , V_23 -> V_46 - sizeof( * V_34 ) ) ;
return 0 ;
V_43:
F_27 ( V_23 ) ;
return - 1 ;
}
void F_28 ( struct V_3 * V_3 , V_38 * V_48 )
{
V_38 * V_49 = V_3 -> V_18 . V_50 ;
V_38 * V_35 = V_3 -> V_51 ;
if ( F_29 ( V_48 ) )
V_48 = V_49 ;
if ( ! F_30 ( V_35 , V_48 ) )
return;
F_7 ( V_16 , V_3 -> V_13 -> V_17 , L_3 , V_48 ) ;
if ( ! F_29 ( V_35 ) && F_30 ( V_35 , V_49 ) )
F_31 ( V_3 -> V_12 , V_35 ) ;
memcpy ( V_35 , V_48 , V_40 ) ;
if ( F_30 ( V_48 , V_49 ) )
F_32 ( V_3 -> V_12 , V_48 ) ;
}
void F_33 ( struct V_20 * V_13 , V_38 * V_48 )
{
struct V_3 * V_3 = F_34 ( V_13 ) ;
F_35 ( & V_3 -> V_8 ) ;
F_28 ( V_3 , V_48 ) ;
F_36 ( & V_3 -> V_8 ) ;
}
void F_37 ( struct V_20 * V_13 , T_1 V_52 , struct V_24 * V_25 )
{
struct V_3 * V_3 = F_34 ( V_13 ) ;
V_38 * V_53 ;
int V_54 ;
F_7 ( V_16 , V_13 -> V_17 , L_4 ,
V_52 , V_25 ) ;
if ( ! V_52 ) {
F_33 ( V_13 , V_3 -> V_18 . V_50 ) ;
F_38 ( V_3 ) ;
return;
}
if ( V_25 ) {
V_53 = F_39 ( V_25 ) -> V_55 ;
if ( F_29 ( V_53 ) ) {
F_40 ( & V_3 -> V_18 , V_13 , V_25 ) ;
}
F_33 ( V_13 , V_53 ) ;
}
F_35 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_27 == V_29 || V_3 -> V_27 == V_28 )
V_3 -> V_27 = V_56 ;
else {
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_5
L_6 ,
F_41 ( V_3 -> V_27 ) ) ;
F_36 ( & V_3 -> V_8 ) ;
return;
}
F_36 ( & V_3 -> V_8 ) ;
V_54 = F_42 ( V_3 , V_52 ) ;
if ( V_54 < 0 ) {
F_35 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_27 == V_56 )
V_3 -> V_27 = V_29 ;
F_36 ( & V_3 -> V_8 ) ;
}
}
static int F_43 ( struct V_57 * V_12 ,
struct V_58 * V_58 , V_38 type ,
T_2 V_59 , T_2 V_60 ,
void * V_61 )
{
struct V_3 * V_3 = F_44 ( V_12 ) ;
F_45 ( & V_3 -> V_62 [ V_59 ] , V_58 , V_60 ,
V_63 , V_64 ,
NULL ) ;
return 0 ;
}
int F_46 ( struct V_3 * V_3 , int V_65 )
{
unsigned int V_66 = 0 , V_67 ;
unsigned int V_68 ;
int V_69 ;
for ( V_68 = 0 ; V_68 < V_3 -> V_70 ; V_68 ++ ) {
V_67 = F_47 ( & V_3 -> V_71 [ V_68 ] , V_65 ,
F_43 ,
NULL ) ;
if ( V_67 ) {
V_69 = F_48 ( & V_3 -> V_62 [ V_68 ] , V_72 ) ;
if ( V_69 )
F_49 ( V_73 , V_3 -> V_13 -> V_17 ,
L_7
L_8 ) ;
}
V_66 += V_67 ;
}
return V_66 ;
}
int V_72 ( struct V_74 * V_62 )
{
struct V_3 * V_3 = F_44 ( V_62 -> V_12 ) ;
struct V_22 * V_23 ;
T_2 V_46 ;
T_3 V_75 ;
V_46 = V_76 + V_77 + V_78 ;
V_23 = F_50 ( V_46 ) ;
if ( ! V_23 ) {
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_9 ) ;
return - V_79 ;
}
F_18 ( V_23 ) ;
F_24 ( V_23 ) ;
F_51 ( V_23 ) ;
F_52 ( V_23 , V_46 ) ;
V_75 = F_53 ( V_3 -> V_80 , V_23 -> V_35 , V_46 , V_81 ) ;
F_54 ( V_62 , V_23 , V_75 , V_46 ) ;
return 0 ;
}
void F_55 ( struct V_74 * V_62 , struct V_82 * V_83 )
{
struct V_24 * V_25 = V_83 -> V_84 ;
struct V_3 * V_3 = F_44 ( V_62 -> V_12 ) ;
F_56 ( V_3 -> V_80 , V_83 -> V_85 , V_83 -> V_46 ,
V_81 ) ;
F_12 ( F_57 ( V_25 ) ) ;
V_83 -> V_84 = NULL ;
}
void F_58 ( struct V_86 * V_87 , struct V_22 * V_23 )
{
struct V_3 * V_3 = F_59 ( V_87 ) ;
struct V_88 * V_89 = & V_3 -> V_89 [ 0 ] ;
T_3 V_75 ;
struct V_30 * V_90 ;
struct V_91 * V_92 ;
unsigned long V_5 ;
if ( ! V_3 -> V_93 ) {
V_90 = (struct V_30 * ) F_60 ( V_23 ) ;
V_92 = (struct V_91 * ) F_61 ( V_23 ,
sizeof( * V_92 ) - sizeof( * V_90 ) ) ;
memcpy ( V_92 , V_90 , 2 * V_40 ) ;
V_92 -> V_94 = F_16 ( V_37 ) ;
V_92 -> V_95 = V_90 -> V_36 ;
V_92 -> V_96 = F_16 ( V_3 -> V_97 ) ;
}
V_75 = F_53 ( V_3 -> V_80 , V_23 -> V_35 , V_23 -> V_46 , V_98 ) ;
F_3 ( & V_3 -> V_99 [ 0 ] , V_5 ) ;
if ( ! F_62 ( V_89 ) ) {
F_56 ( V_3 -> V_80 , V_75 , V_23 -> V_46 , V_98 ) ;
F_4 ( & V_3 -> V_99 [ 0 ] , V_5 ) ;
F_63 ( V_23 ) ;
return;
}
F_64 ( V_89 , V_23 , V_75 , V_23 -> V_46 ,
V_3 -> V_93 , V_3 -> V_97 , 1 ) ;
F_4 ( & V_3 -> V_99 [ 0 ] , V_5 ) ;
}
static int F_65 ( struct V_3 * V_3 , struct V_24 * V_25 )
{
struct V_88 * V_89 = & V_3 -> V_89 [ 0 ] ;
struct V_22 * V_23 ;
T_3 V_75 ;
struct V_30 * V_90 ;
struct V_91 * V_92 ;
struct V_32 * V_32 ;
struct V_100 * V_101 ;
T_1 V_102 , V_103 ;
int V_54 = 0 ;
unsigned long V_5 ;
V_101 = F_66 ( V_25 ) ;
V_23 = F_57 ( V_25 ) ;
if ( F_67 ( V_101 -> V_104 == V_105 ) &&
F_68 ( & V_3 -> V_18 , V_3 -> V_13 , V_23 ) )
return 0 ;
if ( ! V_3 -> V_93 ) {
V_103 = sizeof( * V_92 ) + sizeof( * V_32 ) ;
V_92 = (struct V_91 * ) F_61 ( V_23 , V_103 ) ;
V_90 = (struct V_30 * ) V_92 ;
V_92 -> V_94 = F_16 ( V_37 ) ;
V_92 -> V_95 = F_16 ( V_42 ) ;
V_92 -> V_96 = F_16 ( V_3 -> V_97 ) ;
V_32 = (struct V_32 * ) ( V_92 + 1 ) ;
} else {
V_103 = sizeof( * V_90 ) + sizeof( * V_32 ) ;
V_90 = (struct V_30 * ) F_61 ( V_23 , V_103 ) ;
V_90 -> V_36 = F_16 ( V_42 ) ;
V_32 = (struct V_32 * ) ( V_90 + 1 ) ;
}
if ( V_3 -> V_18 . V_106 )
F_69 ( V_90 -> V_107 , V_101 -> V_108 ) ;
else
memcpy ( V_90 -> V_107 , V_3 -> V_18 . V_109 , V_40 ) ;
memcpy ( V_90 -> V_110 , V_3 -> V_51 , V_40 ) ;
V_102 = V_23 -> V_46 ;
F_70 ( V_102 % 4 ) ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_45 = F_23 ( V_25 ) ;
if ( V_44 )
F_71 ( V_32 , V_44 ) ;
V_75 = F_53 ( V_3 -> V_80 , V_90 , V_102 , V_98 ) ;
F_3 ( & V_3 -> V_99 [ 0 ] , V_5 ) ;
if ( ! F_62 ( V_89 ) ) {
F_56 ( V_3 -> V_80 , V_75 ,
V_102 , V_98 ) ;
V_54 = - 1 ;
goto V_111;
}
F_72 ( V_89 , V_23 , V_75 , V_102 , F_25 ( V_25 ) ,
V_3 -> V_93 , V_3 -> V_97 , 1 , 1 , 1 ) ;
V_111:
F_4 ( & V_3 -> V_99 [ 0 ] , V_5 ) ;
if ( V_54 )
F_73 ( F_57 ( V_25 ) ) ;
return V_54 ;
}
int F_74 ( struct V_20 * V_21 , struct V_24 * V_25 )
{
struct V_3 * V_3 = F_34 ( V_21 ) ;
unsigned long V_5 ;
if ( V_3 -> V_112 ) {
F_12 ( F_57 ( V_25 ) ) ;
return - 1 ;
}
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_27 != V_28 && V_3 -> V_27 != V_29 ) {
F_75 ( & V_3 -> V_113 , F_57 ( V_25 ) ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
return F_65 ( V_3 , V_25 ) ;
}
void F_76 ( struct V_3 * V_3 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
while ( ( V_23 = F_11 ( & V_3 -> V_113 ) ) ) {
V_25 = (struct V_24 * ) V_23 ;
F_65 ( V_3 , V_25 ) ;
}
}
static void F_38 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
enum V_114 V_115 ;
int V_54 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
V_116:
V_115 = V_3 -> V_27 ;
switch ( V_115 ) {
case V_28 :
case V_56 :
default:
V_3 -> V_27 = V_117 ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_54 = F_77 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_27 != V_117 )
goto V_116;
if ( V_54 )
V_3 -> V_27 = V_115 ;
break;
case V_117 :
case V_29 :
break;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_78 ( struct V_88 * V_89 ,
struct V_58 * V_58 ,
struct V_118 * V_83 , void * V_61 )
{
struct V_22 * V_23 = V_83 -> V_84 ;
struct V_24 * V_25 = (struct V_24 * ) V_23 ;
struct V_3 * V_3 = F_44 ( V_89 -> V_12 ) ;
F_56 ( V_3 -> V_80 , V_83 -> V_85 ,
V_83 -> V_46 , V_98 ) ;
F_27 ( F_57 ( V_25 ) ) ;
V_83 -> V_84 = NULL ;
}
static int F_79 ( struct V_57 * V_12 ,
struct V_58 * V_58 , V_38 type ,
T_2 V_59 , T_2 V_60 ,
void * V_61 )
{
struct V_3 * V_3 = F_44 ( V_12 ) ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_99 [ V_59 ] , V_5 ) ;
F_80 ( & V_3 -> V_89 [ V_59 ] , V_58 , V_60 ,
F_78 , NULL ) ;
F_4 ( & V_3 -> V_99 [ V_59 ] , V_5 ) ;
return 0 ;
}
int F_81 ( struct V_3 * V_3 , int V_119 )
{
unsigned int V_120 = 0 ;
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_3 -> V_121 ; V_68 ++ ) {
V_120 += F_47 ( & V_3 -> V_71 [ V_3 -> V_70 + V_68 ] ,
V_119 ,
F_79 ,
NULL ) ;
}
return V_120 ;
}
void F_82 ( struct V_88 * V_89 , struct V_118 * V_83 )
{
struct V_24 * V_25 = V_83 -> V_84 ;
struct V_3 * V_3 = F_44 ( V_89 -> V_12 ) ;
F_56 ( V_3 -> V_80 , V_83 -> V_85 ,
V_83 -> V_46 , V_98 ) ;
F_12 ( F_57 ( V_25 ) ) ;
V_83 -> V_84 = NULL ;
}
