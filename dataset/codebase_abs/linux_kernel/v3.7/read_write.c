static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & V_3 ;
}
static T_1 F_2 ( struct V_1 * V_1 , struct V_4 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
if ( V_5 < 0 && ! F_1 ( V_1 ) )
return - V_7 ;
if ( V_5 > V_6 )
return - V_7 ;
if ( V_5 != V_1 -> V_8 ) {
V_1 -> V_8 = V_5 ;
V_1 -> V_9 = 0 ;
}
return V_5 ;
}
T_1
F_3 ( struct V_1 * V_1 , T_1 V_5 , int V_10 ,
T_1 V_6 , T_1 V_11 )
{
struct V_4 * V_4 = V_1 -> V_12 -> V_13 ;
switch ( V_10 ) {
case V_14 :
V_5 += V_11 ;
break;
case V_15 :
if ( V_5 == 0 )
return V_1 -> V_8 ;
F_4 ( & V_1 -> V_16 ) ;
V_5 = F_2 ( V_1 , V_4 , V_1 -> V_8 + V_5 ,
V_6 ) ;
F_5 ( & V_1 -> V_16 ) ;
return V_5 ;
case V_17 :
if ( V_5 >= V_11 )
return - V_18 ;
break;
case V_19 :
if ( V_5 >= V_11 )
return - V_18 ;
V_5 = V_11 ;
break;
}
return F_2 ( V_1 , V_4 , V_5 , V_6 ) ;
}
T_1 F_6 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
struct V_4 * V_4 = V_1 -> V_12 -> V_13 ;
return F_3 ( V_1 , V_5 , V_10 ,
V_4 -> V_20 -> V_21 ,
F_7 ( V_4 ) ) ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
return V_1 -> V_8 ;
}
T_1 F_9 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
return - V_22 ;
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
struct V_4 * V_4 = V_1 -> V_23 . V_24 -> V_25 ;
T_1 V_26 ;
F_11 ( & V_4 -> V_27 ) ;
switch ( V_10 ) {
case V_14 :
V_5 += F_7 ( V_4 ) ;
break;
case V_15 :
if ( V_5 == 0 ) {
V_26 = V_1 -> V_8 ;
goto V_28;
}
V_5 += V_1 -> V_8 ;
break;
case V_17 :
if ( V_5 >= V_4 -> V_29 ) {
V_26 = - V_18 ;
goto V_28;
}
break;
case V_19 :
if ( V_5 >= V_4 -> V_29 ) {
V_26 = - V_18 ;
goto V_28;
}
V_5 = V_4 -> V_29 ;
break;
}
V_26 = - V_7 ;
if ( V_5 >= 0 || F_1 ( V_1 ) ) {
if ( V_5 != V_1 -> V_8 ) {
V_1 -> V_8 = V_5 ;
V_1 -> V_9 = 0 ;
}
V_26 = V_5 ;
}
V_28:
F_12 ( & V_4 -> V_27 ) ;
return V_26 ;
}
T_1 F_13 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
T_1 (* F_14)( struct V_1 * , T_1 , int );
F_14 = F_9 ;
if ( V_1 -> V_2 & V_30 ) {
if ( V_1 -> V_31 && V_1 -> V_31 -> V_32 )
F_14 = V_1 -> V_31 -> V_32 ;
}
return F_14 ( V_1 , V_5 , V_10 ) ;
}
int F_15 ( int V_33 , struct V_1 * V_1 , T_1 * V_34 , T_2 V_35 )
{
struct V_4 * V_4 ;
T_1 V_36 ;
int V_26 = - V_7 ;
V_4 = V_1 -> V_23 . V_24 -> V_25 ;
if ( F_16 ( ( V_37 ) V_35 < 0 ) )
return V_26 ;
V_36 = * V_34 ;
if ( F_16 ( V_36 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
if ( V_35 >= - V_36 )
return - V_38 ;
} else if ( F_16 ( ( T_1 ) ( V_36 + V_35 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
}
if ( F_16 ( V_4 -> V_39 && F_17 ( V_4 ) ) ) {
V_26 = F_18 (
V_33 == V_40 ? V_41 : V_42 ,
V_4 , V_1 , V_36 , V_35 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_26 = F_19 ( V_1 ,
V_33 == V_40 ? V_43 : V_44 ) ;
if ( V_26 )
return V_26 ;
return V_35 > V_45 ? V_45 : V_35 ;
}
static void F_20 ( struct V_46 * V_47 )
{
F_21 ( V_48 ) ;
if ( ! F_22 ( V_47 ) )
F_23 () ;
else
F_24 ( V_47 ) ;
F_25 ( V_49 ) ;
}
V_37 F_26 ( struct V_1 * V_50 , char T_3 * V_51 , T_2 V_52 , T_1 * V_34 )
{
struct V_53 V_54 = { . V_55 = V_51 , . V_56 = V_52 } ;
struct V_46 V_46 ;
V_37 V_57 ;
F_27 ( & V_46 , V_50 ) ;
V_46 . V_58 = * V_34 ;
V_46 . V_59 = V_52 ;
V_46 . V_60 = V_52 ;
for (; ; ) {
V_57 = V_50 -> V_31 -> V_61 ( & V_46 , & V_54 , 1 , V_46 . V_58 ) ;
if ( V_57 != - V_62 )
break;
F_20 ( & V_46 ) ;
}
if ( - V_63 == V_57 )
V_57 = F_28 ( & V_46 ) ;
* V_34 = V_46 . V_58 ;
return V_57 ;
}
V_37 F_29 ( struct V_1 * V_1 , char T_3 * V_51 , T_2 V_35 , T_1 * V_36 )
{
V_37 V_57 ;
if ( ! ( V_1 -> V_2 & V_64 ) )
return - V_65 ;
if ( ! V_1 -> V_31 || ( ! V_1 -> V_31 -> V_66 && ! V_1 -> V_31 -> V_61 ) )
return - V_7 ;
if ( F_16 ( ! F_30 ( V_67 , V_51 , V_35 ) ) )
return - V_68 ;
V_57 = F_15 ( V_40 , V_1 , V_36 , V_35 ) ;
if ( V_57 >= 0 ) {
V_35 = V_57 ;
if ( V_1 -> V_31 -> V_66 )
V_57 = V_1 -> V_31 -> V_66 ( V_1 , V_51 , V_35 , V_36 ) ;
else
V_57 = F_26 ( V_1 , V_51 , V_35 , V_36 ) ;
if ( V_57 > 0 ) {
F_31 ( V_1 ) ;
F_32 ( V_69 , V_57 ) ;
}
F_33 ( V_69 ) ;
}
return V_57 ;
}
V_37 F_34 ( struct V_1 * V_50 , const char T_3 * V_51 , T_2 V_52 , T_1 * V_34 )
{
struct V_53 V_54 = { . V_55 = ( void T_3 * ) V_51 , . V_56 = V_52 } ;
struct V_46 V_46 ;
V_37 V_57 ;
F_27 ( & V_46 , V_50 ) ;
V_46 . V_58 = * V_34 ;
V_46 . V_59 = V_52 ;
V_46 . V_60 = V_52 ;
for (; ; ) {
V_57 = V_50 -> V_31 -> V_70 ( & V_46 , & V_54 , 1 , V_46 . V_58 ) ;
if ( V_57 != - V_62 )
break;
F_20 ( & V_46 ) ;
}
if ( - V_63 == V_57 )
V_57 = F_28 ( & V_46 ) ;
* V_34 = V_46 . V_58 ;
return V_57 ;
}
V_37 F_35 ( struct V_1 * V_1 , const char T_3 * V_51 , T_2 V_35 , T_1 * V_36 )
{
V_37 V_57 ;
if ( ! ( V_1 -> V_2 & V_71 ) )
return - V_65 ;
if ( ! V_1 -> V_31 || ( ! V_1 -> V_31 -> V_72 && ! V_1 -> V_31 -> V_70 ) )
return - V_7 ;
if ( F_16 ( ! F_30 ( V_73 , V_51 , V_35 ) ) )
return - V_68 ;
V_57 = F_15 ( V_74 , V_1 , V_36 , V_35 ) ;
if ( V_57 >= 0 ) {
V_35 = V_57 ;
if ( V_1 -> V_31 -> V_72 )
V_57 = V_1 -> V_31 -> V_72 ( V_1 , V_51 , V_35 , V_36 ) ;
else
V_57 = F_34 ( V_1 , V_51 , V_35 , V_36 ) ;
if ( V_57 > 0 ) {
F_36 ( V_1 ) ;
F_37 ( V_69 , V_57 ) ;
}
F_38 ( V_69 ) ;
}
return V_57 ;
}
static inline T_1 F_39 ( struct V_1 * V_1 )
{
return V_1 -> V_8 ;
}
static inline void F_40 ( struct V_1 * V_1 , T_1 V_36 )
{
V_1 -> V_8 = V_36 ;
}
T_4 (F_41)( unsigned int V_75 , char T_3 * V_51 ,
T_2 V_35 , T_1 V_36 )
{
struct V_75 V_76 ;
V_37 V_57 = - V_65 ;
if ( V_36 < 0 )
return - V_7 ;
V_76 = F_42 ( V_75 ) ;
if ( V_76 . V_1 ) {
V_57 = - V_22 ;
if ( V_76 . V_1 -> V_2 & V_77 )
V_57 = F_29 ( V_76 . V_1 , V_51 , V_35 , & V_36 ) ;
F_43 ( V_76 ) ;
}
return V_57 ;
}
T_5 long F_44 ( long V_75 , long V_51 , long V_35 , T_1 V_36 )
{
return F_45 ( ( unsigned int ) V_75 , ( char T_3 * ) V_51 ,
( T_2 ) V_35 , V_36 ) ;
}
T_4 (F_46)( unsigned int V_75 , const char T_3 * V_51 ,
T_2 V_35 , T_1 V_36 )
{
struct V_75 V_76 ;
V_37 V_57 = - V_65 ;
if ( V_36 < 0 )
return - V_7 ;
V_76 = F_42 ( V_75 ) ;
if ( V_76 . V_1 ) {
V_57 = - V_22 ;
if ( V_76 . V_1 -> V_2 & V_78 )
V_57 = F_35 ( V_76 . V_1 , V_51 , V_35 , & V_36 ) ;
F_43 ( V_76 ) ;
}
return V_57 ;
}
T_5 long F_47 ( long V_75 , long V_51 , long V_35 , T_1 V_36 )
{
return F_48 ( ( unsigned int ) V_75 , ( const char T_3 * ) V_51 ,
( T_2 ) V_35 , V_36 ) ;
}
unsigned long F_49 ( struct V_53 * V_54 , unsigned long V_79 , T_2 V_80 )
{
unsigned long V_81 = 0 ;
T_2 V_52 = 0 ;
while ( V_81 < V_79 ) {
V_81 ++ ;
if ( V_52 + V_54 -> V_56 >= V_80 ) {
V_54 -> V_56 = V_80 - V_52 ;
break;
}
V_52 += V_54 -> V_56 ;
V_54 ++ ;
}
return V_81 ;
}
V_37 F_50 ( struct V_1 * V_50 , const struct V_53 * V_54 ,
unsigned long V_79 , T_2 V_52 , T_1 * V_34 , T_6 F_14 )
{
struct V_46 V_46 ;
V_37 V_57 ;
F_27 ( & V_46 , V_50 ) ;
V_46 . V_58 = * V_34 ;
V_46 . V_59 = V_52 ;
V_46 . V_60 = V_52 ;
for (; ; ) {
V_57 = F_14 ( & V_46 , V_54 , V_79 , V_46 . V_58 ) ;
if ( V_57 != - V_62 )
break;
F_20 ( & V_46 ) ;
}
if ( V_57 == - V_63 )
V_57 = F_28 ( & V_46 ) ;
* V_34 = V_46 . V_58 ;
return V_57 ;
}
V_37 F_51 ( struct V_1 * V_50 , struct V_53 * V_54 ,
unsigned long V_79 , T_1 * V_34 , T_7 F_14 )
{
struct V_53 * V_82 = V_54 ;
V_37 V_57 = 0 ;
while ( V_79 > 0 ) {
void T_3 * V_83 ;
T_2 V_52 ;
V_37 V_84 ;
V_83 = V_82 -> V_55 ;
V_52 = V_82 -> V_56 ;
V_82 ++ ;
V_79 -- ;
V_84 = F_14 ( V_50 , V_83 , V_52 , V_34 ) ;
if ( V_84 < 0 ) {
if ( ! V_57 )
V_57 = V_84 ;
break;
}
V_57 += V_84 ;
if ( V_84 != V_52 )
break;
}
return V_57 ;
}
V_37 F_52 ( int type , const struct V_53 T_3 * V_85 ,
unsigned long V_79 , unsigned long V_86 ,
struct V_53 * V_87 ,
struct V_53 * * V_88 )
{
unsigned long V_81 ;
V_37 V_57 ;
struct V_53 * V_54 = V_87 ;
if ( V_79 == 0 ) {
V_57 = 0 ;
goto V_28;
}
if ( V_79 > V_89 ) {
V_57 = - V_7 ;
goto V_28;
}
if ( V_79 > V_86 ) {
V_54 = F_53 ( V_79 * sizeof( struct V_53 ) , V_90 ) ;
if ( V_54 == NULL ) {
V_57 = - V_91 ;
goto V_28;
}
}
if ( F_54 ( V_54 , V_85 , V_79 * sizeof( * V_85 ) ) ) {
V_57 = - V_68 ;
goto V_28;
}
V_57 = 0 ;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ ) {
void T_3 * V_51 = V_54 [ V_81 ] . V_55 ;
V_37 V_52 = ( V_37 ) V_54 [ V_81 ] . V_56 ;
if ( V_52 < 0 ) {
V_57 = - V_7 ;
goto V_28;
}
if ( type >= 0
&& F_16 ( ! F_30 ( F_55 ( type ) , V_51 , V_52 ) ) ) {
V_57 = - V_68 ;
goto V_28;
}
if ( V_52 > V_45 - V_57 ) {
V_52 = V_45 - V_57 ;
V_54 [ V_81 ] . V_56 = V_52 ;
}
V_57 += V_52 ;
}
V_28:
* V_88 = V_54 ;
return V_57 ;
}
static V_37 F_56 ( int type , struct V_1 * V_1 ,
const struct V_53 T_3 * V_85 ,
unsigned long V_79 , T_1 * V_36 )
{
T_2 V_92 ;
struct V_53 V_93 [ V_94 ] ;
struct V_53 * V_54 = V_93 ;
V_37 V_57 ;
T_7 F_14 ;
T_6 V_95 ;
if ( ! V_1 -> V_31 ) {
V_57 = - V_7 ;
goto V_28;
}
V_57 = F_52 ( type , V_85 , V_79 ,
F_57 ( V_93 ) , V_93 , & V_54 ) ;
if ( V_57 <= 0 )
goto V_28;
V_92 = V_57 ;
V_57 = F_15 ( type , V_1 , V_36 , V_92 ) ;
if ( V_57 < 0 )
goto V_28;
V_95 = NULL ;
if ( type == V_40 ) {
F_14 = V_1 -> V_31 -> V_66 ;
V_95 = V_1 -> V_31 -> V_61 ;
} else {
F_14 = ( T_7 ) V_1 -> V_31 -> V_72 ;
V_95 = V_1 -> V_31 -> V_70 ;
}
if ( V_95 )
V_57 = F_50 ( V_1 , V_54 , V_79 , V_92 ,
V_36 , V_95 ) ;
else
V_57 = F_51 ( V_1 , V_54 , V_79 , V_36 , F_14 ) ;
V_28:
if ( V_54 != V_93 )
F_58 ( V_54 ) ;
if ( ( V_57 + ( type == V_40 ) ) > 0 ) {
if ( type == V_40 )
F_31 ( V_1 ) ;
else
F_36 ( V_1 ) ;
}
return V_57 ;
}
V_37 F_59 ( struct V_1 * V_1 , const struct V_53 T_3 * V_96 ,
unsigned long V_97 , T_1 * V_36 )
{
if ( ! ( V_1 -> V_2 & V_64 ) )
return - V_65 ;
if ( ! V_1 -> V_31 || ( ! V_1 -> V_31 -> V_61 && ! V_1 -> V_31 -> V_66 ) )
return - V_7 ;
return F_56 ( V_40 , V_1 , V_96 , V_97 , V_36 ) ;
}
V_37 F_60 ( struct V_1 * V_1 , const struct V_53 T_3 * V_96 ,
unsigned long V_97 , T_1 * V_36 )
{
if ( ! ( V_1 -> V_2 & V_71 ) )
return - V_65 ;
if ( ! V_1 -> V_31 || ( ! V_1 -> V_31 -> V_70 && ! V_1 -> V_31 -> V_72 ) )
return - V_7 ;
return F_56 ( V_74 , V_1 , V_96 , V_97 , V_36 ) ;
}
static inline T_1 F_61 ( unsigned long V_98 , unsigned long V_99 )
{
#define F_62 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_98 << F_62 ) << F_62 ) | V_99 ;
}
V_37 F_63 ( int V_100 , int V_101 , T_1 * V_34 , T_2 V_35 ,
T_1 V_102 )
{
struct V_75 V_103 , V_28 ;
struct V_4 * V_104 , * V_105 ;
T_1 V_36 ;
V_37 V_26 ;
int V_106 ;
V_26 = - V_65 ;
V_103 = F_42 ( V_101 ) ;
if ( ! V_103 . V_1 )
goto V_28;
if ( ! ( V_103 . V_1 -> V_2 & V_64 ) )
goto V_107;
V_26 = - V_22 ;
if ( ! V_34 )
V_34 = & V_103 . V_1 -> V_8 ;
else
if ( ! ( V_103 . V_1 -> V_2 & V_77 ) )
goto V_107;
V_26 = F_15 ( V_40 , V_103 . V_1 , V_34 , V_35 ) ;
if ( V_26 < 0 )
goto V_107;
V_35 = V_26 ;
V_26 = - V_65 ;
V_28 = F_42 ( V_100 ) ;
if ( ! V_28 . V_1 )
goto V_107;
if ( ! ( V_28 . V_1 -> V_2 & V_71 ) )
goto V_108;
V_26 = - V_7 ;
V_104 = V_103 . V_1 -> V_23 . V_24 -> V_25 ;
V_105 = V_28 . V_1 -> V_23 . V_24 -> V_25 ;
V_26 = F_15 ( V_74 , V_28 . V_1 , & V_28 . V_1 -> V_8 , V_35 ) ;
if ( V_26 < 0 )
goto V_108;
V_35 = V_26 ;
if ( ! V_102 )
V_102 = F_64 ( V_104 -> V_20 -> V_21 , V_105 -> V_20 -> V_21 ) ;
V_36 = * V_34 ;
if ( F_16 ( V_36 + V_35 > V_102 ) ) {
V_26 = - V_38 ;
if ( V_36 >= V_102 )
goto V_108;
V_35 = V_102 - V_36 ;
}
V_106 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
V_26 = F_65 ( V_103 . V_1 , V_34 , V_28 . V_1 , V_35 , V_106 ) ;
if ( V_26 > 0 ) {
F_32 ( V_69 , V_26 ) ;
F_37 ( V_69 , V_26 ) ;
}
F_33 ( V_69 ) ;
F_38 ( V_69 ) ;
if ( * V_34 > V_102 )
V_26 = - V_38 ;
V_108:
F_43 ( V_28 ) ;
V_107:
F_43 ( V_103 ) ;
V_28:
return V_26 ;
}
