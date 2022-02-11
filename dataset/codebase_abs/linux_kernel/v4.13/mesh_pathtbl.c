static T_1 F_1 ( const void * V_1 , T_1 V_2 , T_1 V_3 )
{
return F_2 ( * ( T_1 * ) ( V_1 + 2 ) , V_3 ) ;
}
static inline bool F_3 ( struct V_4 * V_5 )
{
return ( V_5 -> V_6 & V_7 ) &&
F_4 ( V_8 , V_5 -> V_9 ) &&
! ( V_5 -> V_6 & V_10 ) ;
}
static void F_5 ( void * V_11 , void * V_12 )
{
struct V_4 * V_5 = V_11 ;
struct V_13 * V_14 = V_12 ;
F_6 ( V_14 , V_5 ) ;
}
static struct V_13 * F_7 ( void )
{
struct V_13 * V_15 ;
V_15 = F_8 ( sizeof( struct V_13 ) , V_16 ) ;
if ( ! V_15 )
return NULL ;
F_9 ( & V_15 -> V_17 ) ;
F_10 ( & V_15 -> V_18 , 0 ) ;
F_11 ( & V_15 -> V_19 ) ;
return V_15 ;
}
static void F_12 ( struct V_13 * V_14 )
{
F_13 ( & V_14 -> V_20 ,
F_5 , V_14 ) ;
F_14 ( V_14 ) ;
}
void F_15 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
unsigned long V_6 ;
F_16 ( V_5 -> V_27 , V_22 ) ;
F_17 ( & V_5 -> V_28 . V_29 , V_6 ) ;
F_18 (&mpath->frame_queue, skb) {
V_26 = (struct V_25 * ) V_24 -> V_30 ;
memcpy ( V_26 -> V_31 , V_22 -> V_22 . V_1 , V_32 ) ;
memcpy ( V_26 -> V_33 , V_5 -> V_34 -> V_35 . V_1 , V_32 ) ;
F_19 ( V_22 -> V_34 , V_22 , V_26 ) ;
}
F_20 ( & V_5 -> V_28 . V_29 , V_6 ) ;
}
static void F_21 ( struct V_23 * V_24 , char * V_36 ,
struct V_4 * V_37 )
{
struct V_25 * V_26 ;
struct V_38 * V_39 ;
int V_40 , V_41 ;
char * V_27 ;
V_26 = (struct V_25 * ) V_24 -> V_30 ;
V_41 = F_22 ( V_26 -> V_42 ) ;
V_39 = (struct V_38 * ) ( V_24 -> V_30 + V_41 ) ;
if ( ! ( V_39 -> V_6 & V_43 ) ) {
V_40 = 6 ;
F_23 ( V_24 , 2 * V_32 ) ;
memmove ( V_24 -> V_30 , V_26 , V_41 + V_40 ) ;
V_26 = (struct V_25 * ) V_24 -> V_30 ;
V_39 = (struct V_38 * ) ( V_24 -> V_30 + V_41 ) ;
V_39 -> V_6 = V_44 ;
memcpy ( V_39 -> V_45 , V_26 -> V_46 , V_32 ) ;
memcpy ( V_39 -> V_47 , V_26 -> V_48 , V_32 ) ;
}
V_26 = (struct V_25 * ) V_24 -> V_30 ;
F_24 () ;
V_27 = F_25 ( V_37 -> V_27 ) -> V_22 . V_1 ;
memcpy ( V_26 -> V_31 , V_27 , V_32 ) ;
F_26 () ;
memcpy ( V_26 -> V_33 , V_37 -> V_34 -> V_35 . V_1 , V_32 ) ;
memcpy ( V_26 -> V_46 , V_36 , V_32 ) ;
}
static void F_27 ( struct V_4 * V_37 ,
struct V_4 * V_49 ,
bool V_50 )
{
struct V_23 * V_24 , * V_51 , * V_52 ;
struct V_53 V_54 ;
unsigned long V_6 ;
if ( F_28 ( V_37 == V_49 ) )
return;
if ( F_28 ( ! V_37 -> V_27 ) )
return;
F_29 ( & V_54 ) ;
F_17 ( & V_49 -> V_28 . V_29 , V_6 ) ;
F_30 ( & V_49 -> V_28 , & V_54 ) ;
F_20 ( & V_49 -> V_28 . V_29 , V_6 ) ;
F_31 (&failq, fskb, tmp) {
if ( F_32 ( & V_37 -> V_28 ) >=
V_55 ) {
F_33 ( V_37 -> V_34 , L_1 ) ;
break;
}
V_24 = F_34 ( V_51 , V_16 ) ;
if ( F_28 ( ! V_24 ) )
break;
F_21 ( V_24 , V_37 -> V_56 , V_37 ) ;
F_35 ( & V_37 -> V_28 , V_24 ) ;
if ( V_50 )
continue;
F_36 ( V_51 , & V_54 ) ;
F_37 ( V_51 ) ;
}
F_33 ( V_37 -> V_34 , L_2 ,
V_37 -> V_56 , F_32 ( & V_37 -> V_28 ) ) ;
if ( ! V_50 )
return;
F_17 ( & V_49 -> V_28 . V_29 , V_6 ) ;
F_38 ( & V_54 , & V_49 -> V_28 ) ;
F_20 ( & V_49 -> V_28 . V_29 , V_6 ) ;
}
static struct V_4 * F_39 ( struct V_13 * V_14 , const T_2 * V_56 ,
struct V_57 * V_34 )
{
struct V_4 * V_5 ;
V_5 = F_40 ( & V_14 -> V_20 , V_56 , V_58 ) ;
if ( V_5 && F_3 ( V_5 ) ) {
F_41 ( & V_5 -> V_59 ) ;
V_5 -> V_6 &= ~ V_7 ;
F_42 ( & V_5 -> V_59 ) ;
}
return V_5 ;
}
struct V_4 *
F_43 ( struct V_57 * V_34 , const T_2 * V_56 )
{
return F_39 ( V_34 -> V_60 . V_61 . V_62 , V_56 , V_34 ) ;
}
struct V_4 *
F_44 ( struct V_57 * V_34 , const T_2 * V_56 )
{
return F_39 ( V_34 -> V_60 . V_61 . V_63 , V_56 , V_34 ) ;
}
static struct V_4 *
F_45 ( struct V_13 * V_14 , int V_64 )
{
int V_65 = 0 , V_66 ;
struct V_4 * V_5 = NULL ;
struct V_67 V_68 ;
V_66 = F_46 ( & V_14 -> V_20 , & V_68 , V_16 ) ;
if ( V_66 )
return NULL ;
V_66 = F_47 ( & V_68 ) ;
if ( V_66 && V_66 != - V_69 )
goto V_70;
while ( ( V_5 = F_48 ( & V_68 ) ) ) {
if ( F_49 ( V_5 ) && F_50 ( V_5 ) == - V_69 )
continue;
if ( F_49 ( V_5 ) )
break;
if ( V_65 ++ == V_64 )
break;
}
V_70:
F_51 ( & V_68 ) ;
F_52 ( & V_68 ) ;
if ( F_49 ( V_5 ) || ! V_5 )
return NULL ;
if ( F_3 ( V_5 ) ) {
F_41 ( & V_5 -> V_59 ) ;
V_5 -> V_6 &= ~ V_7 ;
F_42 ( & V_5 -> V_59 ) ;
}
return V_5 ;
}
struct V_4 *
F_53 ( struct V_57 * V_34 , int V_64 )
{
return F_45 ( V_34 -> V_60 . V_61 . V_62 , V_64 ) ;
}
struct V_4 *
F_54 ( struct V_57 * V_34 , int V_64 )
{
return F_45 ( V_34 -> V_60 . V_61 . V_63 , V_64 ) ;
}
int F_55 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_70 ;
F_24 () ;
V_14 = V_5 -> V_34 -> V_60 . V_61 . V_62 ;
F_41 ( & V_5 -> V_59 ) ;
if ( V_5 -> V_71 ) {
V_70 = - V_72 ;
F_42 ( & V_5 -> V_59 ) ;
goto V_73;
}
V_5 -> V_71 = true ;
V_5 -> V_34 -> V_60 . V_61 . V_74 ++ ;
F_56 ( & V_14 -> V_19 ) ;
F_57 ( & V_5 -> V_75 , & V_14 -> V_17 ) ;
F_58 ( & V_14 -> V_19 ) ;
F_42 ( & V_5 -> V_59 ) ;
F_33 ( V_5 -> V_34 ,
L_3 ,
V_5 -> V_56 , V_5 -> V_34 -> V_60 . V_61 . V_74 ) ;
V_70 = 0 ;
V_73:
F_26 () ;
return V_70 ;
}
static void F_59 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
F_60 ( & V_5 -> V_59 ) ;
if ( ! V_5 -> V_71 )
return;
V_5 -> V_71 = false ;
F_41 ( & V_14 -> V_19 ) ;
F_61 ( & V_5 -> V_75 ) ;
V_5 -> V_34 -> V_60 . V_61 . V_74 -- ;
F_42 ( & V_14 -> V_19 ) ;
F_33 ( V_5 -> V_34 ,
L_4 ,
V_5 -> V_56 , V_5 -> V_34 -> V_60 . V_61 . V_74 ) ;
}
int F_62 ( struct V_57 * V_34 )
{
return V_34 -> V_60 . V_61 . V_74 ;
}
static
struct V_4 * F_63 ( struct V_57 * V_34 ,
const T_2 * V_56 , T_3 V_76 )
{
struct V_4 * V_77 ;
V_77 = F_64 ( sizeof( struct V_4 ) , V_76 ) ;
if ( ! V_77 )
return NULL ;
memcpy ( V_77 -> V_56 , V_56 , V_32 ) ;
F_65 ( V_77 -> V_78 ) ;
V_77 -> V_79 = false ;
V_77 -> V_34 = V_34 ;
V_77 -> V_6 = 0 ;
F_66 ( & V_77 -> V_28 ) ;
V_77 -> V_9 = V_8 ;
F_11 ( & V_77 -> V_59 ) ;
F_67 ( & V_77 -> V_80 , V_81 ,
( unsigned long ) V_77 ) ;
return V_77 ;
}
struct V_4 * F_68 ( struct V_57 * V_34 ,
const T_2 * V_56 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 , * V_77 ;
int V_66 ;
if ( F_69 ( V_56 , V_34 -> V_35 . V_1 ) )
return F_70 ( - V_82 ) ;
if ( F_71 ( V_56 ) )
return F_70 ( - V_82 ) ;
if ( F_72 ( & V_34 -> V_60 . V_61 . V_83 , 1 , V_84 ) == 0 )
return F_70 ( - V_85 ) ;
V_77 = F_63 ( V_34 , V_56 , V_16 ) ;
if ( ! V_77 )
return F_70 ( - V_86 ) ;
V_14 = V_34 -> V_60 . V_61 . V_62 ;
do {
V_66 = F_73 ( & V_14 -> V_20 ,
& V_77 -> V_87 ,
V_58 ) ;
if ( V_66 == - V_72 )
V_5 = F_40 ( & V_14 -> V_20 ,
V_56 ,
V_58 ) ;
} while ( F_74 ( V_66 == - V_72 && ! V_5 ) );
if ( V_66 && V_66 != - V_72 )
return F_70 ( V_66 ) ;
if ( V_66 == - V_72 ) {
F_14 ( V_77 ) ;
V_77 = V_5 ;
}
V_34 -> V_60 . V_61 . V_88 ++ ;
return V_77 ;
}
int F_75 ( struct V_57 * V_34 ,
const T_2 * V_56 , const T_2 * V_89 )
{
struct V_13 * V_14 ;
struct V_4 * V_77 ;
int V_66 ;
if ( F_69 ( V_56 , V_34 -> V_35 . V_1 ) )
return - V_82 ;
if ( F_71 ( V_56 ) )
return - V_82 ;
V_77 = F_63 ( V_34 , V_56 , V_16 ) ;
if ( ! V_77 )
return - V_86 ;
memcpy ( V_77 -> V_89 , V_89 , V_32 ) ;
V_14 = V_34 -> V_60 . V_61 . V_63 ;
V_66 = F_73 ( & V_14 -> V_20 ,
& V_77 -> V_87 ,
V_58 ) ;
V_34 -> V_60 . V_61 . V_90 ++ ;
return V_66 ;
}
void F_76 ( struct V_21 * V_22 )
{
struct V_57 * V_34 = V_22 -> V_34 ;
struct V_13 * V_14 = V_34 -> V_60 . V_61 . V_62 ;
static const T_2 V_91 [ V_32 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_4 * V_5 ;
struct V_67 V_68 ;
int V_66 ;
V_66 = F_46 ( & V_14 -> V_20 , & V_68 , V_16 ) ;
if ( V_66 )
return;
V_66 = F_47 ( & V_68 ) ;
if ( V_66 && V_66 != - V_69 )
goto V_92;
while ( ( V_5 = F_48 ( & V_68 ) ) ) {
if ( F_49 ( V_5 ) && F_50 ( V_5 ) == - V_69 )
continue;
if ( F_49 ( V_5 ) )
break;
if ( F_77 ( V_5 -> V_27 ) == V_22 &&
V_5 -> V_6 & V_7 &&
! ( V_5 -> V_6 & V_10 ) ) {
F_41 ( & V_5 -> V_59 ) ;
V_5 -> V_6 &= ~ V_7 ;
++ V_5 -> V_93 ;
F_42 ( & V_5 -> V_59 ) ;
F_78 ( V_34 ,
V_34 -> V_60 . V_61 . V_94 . V_95 ,
V_5 -> V_56 , V_5 -> V_93 ,
V_96 , V_91 ) ;
}
}
V_92:
F_51 ( & V_68 ) ;
F_52 ( & V_68 ) ;
}
static void F_6 ( struct V_13 * V_14 ,
struct V_4 * V_5 )
{
struct V_57 * V_34 = V_5 -> V_34 ;
F_41 ( & V_5 -> V_59 ) ;
V_5 -> V_6 |= V_97 | V_98 ;
F_59 ( V_14 , V_5 ) ;
F_42 ( & V_5 -> V_59 ) ;
F_79 ( & V_5 -> V_80 ) ;
F_80 ( & V_34 -> V_60 . V_61 . V_83 ) ;
F_80 ( & V_14 -> V_18 ) ;
F_81 ( V_5 , V_99 ) ;
}
static void F_82 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
F_83 ( & V_14 -> V_20 , & V_5 -> V_87 , V_58 ) ;
F_6 ( V_14 , V_5 ) ;
}
void F_84 ( struct V_21 * V_22 )
{
struct V_57 * V_34 = V_22 -> V_34 ;
struct V_13 * V_14 = V_34 -> V_60 . V_61 . V_62 ;
struct V_4 * V_5 ;
struct V_67 V_68 ;
int V_66 ;
V_66 = F_46 ( & V_14 -> V_20 , & V_68 , V_16 ) ;
if ( V_66 )
return;
V_66 = F_47 ( & V_68 ) ;
if ( V_66 && V_66 != - V_69 )
goto V_92;
while ( ( V_5 = F_48 ( & V_68 ) ) ) {
if ( F_49 ( V_5 ) && F_50 ( V_5 ) == - V_69 )
continue;
if ( F_49 ( V_5 ) )
break;
if ( F_77 ( V_5 -> V_27 ) == V_22 )
F_82 ( V_14 , V_5 ) ;
}
V_92:
F_51 ( & V_68 ) ;
F_52 ( & V_68 ) ;
}
static void F_85 ( struct V_57 * V_34 ,
const T_2 * V_100 )
{
struct V_13 * V_14 = V_34 -> V_60 . V_61 . V_63 ;
struct V_4 * V_5 ;
struct V_67 V_68 ;
int V_66 ;
V_66 = F_46 ( & V_14 -> V_20 , & V_68 , V_16 ) ;
if ( V_66 )
return;
V_66 = F_47 ( & V_68 ) ;
if ( V_66 && V_66 != - V_69 )
goto V_92;
while ( ( V_5 = F_48 ( & V_68 ) ) ) {
if ( F_49 ( V_5 ) && F_50 ( V_5 ) == - V_69 )
continue;
if ( F_49 ( V_5 ) )
break;
if ( F_69 ( V_5 -> V_89 , V_100 ) )
F_82 ( V_14 , V_5 ) ;
}
V_92:
F_51 ( & V_68 ) ;
F_52 ( & V_68 ) ;
}
static void F_86 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_67 V_68 ;
int V_66 ;
V_66 = F_46 ( & V_14 -> V_20 , & V_68 , V_16 ) ;
if ( V_66 )
return;
V_66 = F_47 ( & V_68 ) ;
if ( V_66 && V_66 != - V_69 )
goto V_92;
while ( ( V_5 = F_48 ( & V_68 ) ) ) {
if ( F_49 ( V_5 ) && F_50 ( V_5 ) == - V_69 )
continue;
if ( F_49 ( V_5 ) )
break;
F_82 ( V_14 , V_5 ) ;
}
V_92:
F_51 ( & V_68 ) ;
F_52 ( & V_68 ) ;
}
void F_87 ( struct V_57 * V_34 )
{
F_86 ( V_34 -> V_60 . V_61 . V_62 ) ;
F_86 ( V_34 -> V_60 . V_61 . V_63 ) ;
}
static int F_88 ( struct V_13 * V_14 ,
struct V_57 * V_34 ,
const T_2 * V_1 )
{
struct V_4 * V_5 ;
F_24 () ;
V_5 = F_40 ( & V_14 -> V_20 , V_1 , V_58 ) ;
if ( ! V_5 ) {
F_26 () ;
return - V_101 ;
}
F_82 ( V_14 , V_5 ) ;
F_26 () ;
return 0 ;
}
int F_89 ( struct V_57 * V_34 , const T_2 * V_1 )
{
int V_70 ;
F_85 ( V_34 , V_1 ) ;
V_70 = F_88 ( V_34 -> V_60 . V_61 . V_62 , V_34 , V_1 ) ;
V_34 -> V_60 . V_61 . V_88 ++ ;
return V_70 ;
}
void F_90 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 & V_7 )
F_91 ( V_5 -> V_34 -> V_102 ,
& V_5 -> V_28 ) ;
}
int F_92 ( struct V_4 * V_5 )
{
struct V_57 * V_34 = V_5 -> V_34 ;
struct V_13 * V_14 ;
struct V_4 * V_49 = V_5 ;
struct V_4 * V_103 ;
bool V_50 = false ;
V_14 = V_34 -> V_60 . V_61 . V_62 ;
F_24 () ;
F_93 (gate, &tbl->known_gates, gate_list) {
if ( V_103 -> V_6 & V_7 ) {
F_33 ( V_34 , L_5 , V_103 -> V_56 ) ;
F_27 ( V_103 , V_49 , V_50 ) ;
V_49 = V_103 ;
V_50 = true ;
} else {
F_33 ( V_34 ,
L_6 ,
V_103 -> V_56 , V_103 -> V_6 ) ;
}
}
F_93 (gate, &tbl->known_gates, gate_list) {
F_33 ( V_34 , L_7 , V_103 -> V_56 ) ;
F_90 ( V_103 ) ;
}
F_26 () ;
return ( V_49 == V_5 ) ? - V_104 : 0 ;
}
void F_94 ( struct V_57 * V_34 ,
struct V_23 * V_24 )
{
F_37 ( V_24 ) ;
V_34 -> V_60 . V_61 . V_105 . V_106 ++ ;
}
void F_95 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
while ( ( V_24 = F_96 ( & V_5 -> V_28 ) ) != NULL )
F_94 ( V_5 -> V_34 , V_24 ) ;
}
void F_97 ( struct V_4 * V_5 , struct V_21 * V_27 )
{
F_41 ( & V_5 -> V_59 ) ;
F_15 ( V_5 , V_27 ) ;
V_5 -> V_93 = 0xffff ;
V_5 -> V_107 = 0 ;
V_5 -> V_108 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_6 = V_10 | V_109 ;
F_98 ( V_5 ) ;
F_42 ( & V_5 -> V_59 ) ;
F_99 ( & V_27 -> V_61 -> V_110 ) ;
F_100 ( & V_27 -> V_61 -> V_110 , 1 ) ;
F_90 ( V_5 ) ;
}
int F_101 ( struct V_57 * V_34 )
{
struct V_13 * V_111 , * V_112 ;
int V_66 ;
V_111 = F_7 () ;
if ( ! V_111 )
return - V_86 ;
V_112 = F_7 () ;
if ( ! V_112 ) {
V_66 = - V_86 ;
goto V_113;
}
F_102 ( & V_111 -> V_20 , & V_58 ) ;
F_102 ( & V_112 -> V_20 , & V_58 ) ;
V_34 -> V_60 . V_61 . V_62 = V_111 ;
V_34 -> V_60 . V_61 . V_63 = V_112 ;
return 0 ;
V_113:
F_12 ( V_111 ) ;
return V_66 ;
}
static
void F_103 ( struct V_57 * V_34 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_67 V_68 ;
int V_66 ;
V_66 = F_46 ( & V_14 -> V_20 , & V_68 , V_114 ) ;
if ( V_66 )
return;
V_66 = F_47 ( & V_68 ) ;
if ( V_66 && V_66 != - V_69 )
goto V_92;
while ( ( V_5 = F_48 ( & V_68 ) ) ) {
if ( F_49 ( V_5 ) && F_50 ( V_5 ) == - V_69 )
continue;
if ( F_49 ( V_5 ) )
break;
if ( ( ! ( V_5 -> V_6 & V_97 ) ) &&
( ! ( V_5 -> V_6 & V_10 ) ) &&
F_4 ( V_8 , V_5 -> V_9 + V_115 ) )
F_82 ( V_14 , V_5 ) ;
}
V_92:
F_51 ( & V_68 ) ;
F_52 ( & V_68 ) ;
}
void F_104 ( struct V_57 * V_34 )
{
F_103 ( V_34 , V_34 -> V_60 . V_61 . V_62 ) ;
F_103 ( V_34 , V_34 -> V_60 . V_61 . V_63 ) ;
}
void F_105 ( struct V_57 * V_34 )
{
F_12 ( V_34 -> V_60 . V_61 . V_62 ) ;
F_12 ( V_34 -> V_60 . V_61 . V_63 ) ;
}
