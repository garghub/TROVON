static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & V_3 ;
}
T_1
F_2 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
struct V_6 * V_6 = V_1 -> V_7 -> V_8 ;
switch ( V_5 ) {
case V_9 :
V_4 += V_6 -> V_10 ;
break;
case V_11 :
if ( V_4 == 0 )
return V_1 -> V_12 ;
V_4 += V_1 -> V_12 ;
break;
}
if ( V_4 < 0 && ! F_1 ( V_1 ) )
return - V_13 ;
if ( V_4 > V_6 -> V_14 -> V_15 )
return - V_13 ;
if ( V_4 != V_1 -> V_12 ) {
V_1 -> V_12 = V_4 ;
V_1 -> V_16 = 0 ;
}
return V_4 ;
}
T_1 F_3 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
T_1 V_17 ;
F_4 ( & V_1 -> V_18 -> V_19 -> V_20 ) ;
V_17 = F_2 ( V_1 , V_4 , V_5 ) ;
F_5 ( & V_1 -> V_18 -> V_19 -> V_20 ) ;
return V_17 ;
}
T_1 F_6 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
return V_1 -> V_12 ;
}
T_1 F_7 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
return - V_21 ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
T_1 V_22 ;
F_4 ( & V_1 -> V_18 -> V_19 -> V_20 ) ;
switch ( V_5 ) {
case V_9 :
V_4 += F_9 ( V_1 -> V_23 . V_24 -> V_19 ) ;
break;
case V_11 :
if ( V_4 == 0 ) {
V_22 = V_1 -> V_12 ;
goto V_25;
}
V_4 += V_1 -> V_12 ;
}
V_22 = - V_13 ;
if ( V_4 >= 0 || F_1 ( V_1 ) ) {
if ( V_4 != V_1 -> V_12 ) {
V_1 -> V_12 = V_4 ;
V_1 -> V_16 = 0 ;
}
V_22 = V_4 ;
}
V_25:
F_5 ( & V_1 -> V_18 -> V_19 -> V_20 ) ;
return V_22 ;
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
T_1 (* F_11)( struct V_1 * , T_1 , int );
F_11 = F_7 ;
if ( V_1 -> V_2 & V_26 ) {
if ( V_1 -> V_27 && V_1 -> V_27 -> V_28 )
F_11 = V_1 -> V_27 -> V_28 ;
}
return F_11 ( V_1 , V_4 , V_5 ) ;
}
int F_12 ( int V_29 , struct V_1 * V_1 , T_1 * V_30 , T_2 V_31 )
{
struct V_6 * V_6 ;
T_1 V_32 ;
int V_22 = - V_13 ;
V_6 = V_1 -> V_23 . V_24 -> V_19 ;
if ( F_13 ( ( V_33 ) V_31 < 0 ) )
return V_22 ;
V_32 = * V_30 ;
if ( F_13 ( V_32 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_22 ;
if ( V_31 >= - V_32 )
return - V_34 ;
} else if ( F_13 ( ( T_1 ) ( V_32 + V_31 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_22 ;
}
if ( F_13 ( V_6 -> V_35 && F_14 ( V_6 ) ) ) {
V_22 = F_15 (
V_29 == V_36 ? V_37 : V_38 ,
V_6 , V_1 , V_32 , V_31 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_16 ( V_1 ,
V_29 == V_36 ? V_39 : V_40 ) ;
if ( V_22 )
return V_22 ;
return V_31 > V_41 ? V_41 : V_31 ;
}
static void F_17 ( struct V_42 * V_43 )
{
F_18 ( V_44 ) ;
if ( ! F_19 ( V_43 ) )
F_20 () ;
else
F_21 ( V_43 ) ;
F_22 ( V_45 ) ;
}
V_33 F_23 ( struct V_1 * V_46 , char T_3 * V_47 , T_2 V_48 , T_1 * V_30 )
{
struct V_49 V_50 = { . V_51 = V_47 , . V_52 = V_48 } ;
struct V_42 V_42 ;
V_33 V_53 ;
F_24 ( & V_42 , V_46 ) ;
V_42 . V_54 = * V_30 ;
V_42 . V_55 = V_48 ;
V_42 . V_56 = V_48 ;
for (; ; ) {
V_53 = V_46 -> V_27 -> V_57 ( & V_42 , & V_50 , 1 , V_42 . V_54 ) ;
if ( V_53 != - V_58 )
break;
F_17 ( & V_42 ) ;
}
if ( - V_59 == V_53 )
V_53 = F_25 ( & V_42 ) ;
* V_30 = V_42 . V_54 ;
return V_53 ;
}
V_33 F_26 ( struct V_1 * V_1 , char T_3 * V_47 , T_2 V_31 , T_1 * V_32 )
{
V_33 V_53 ;
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_61 ;
if ( ! V_1 -> V_27 || ( ! V_1 -> V_27 -> V_62 && ! V_1 -> V_27 -> V_57 ) )
return - V_13 ;
if ( F_13 ( ! F_27 ( V_63 , V_47 , V_31 ) ) )
return - V_64 ;
V_53 = F_12 ( V_36 , V_1 , V_32 , V_31 ) ;
if ( V_53 >= 0 ) {
V_31 = V_53 ;
if ( V_1 -> V_27 -> V_62 )
V_53 = V_1 -> V_27 -> V_62 ( V_1 , V_47 , V_31 , V_32 ) ;
else
V_53 = F_23 ( V_1 , V_47 , V_31 , V_32 ) ;
if ( V_53 > 0 ) {
F_28 ( V_1 ) ;
F_29 ( V_65 , V_53 ) ;
}
F_30 ( V_65 ) ;
}
return V_53 ;
}
V_33 F_31 ( struct V_1 * V_46 , const char T_3 * V_47 , T_2 V_48 , T_1 * V_30 )
{
struct V_49 V_50 = { . V_51 = ( void T_3 * ) V_47 , . V_52 = V_48 } ;
struct V_42 V_42 ;
V_33 V_53 ;
F_24 ( & V_42 , V_46 ) ;
V_42 . V_54 = * V_30 ;
V_42 . V_55 = V_48 ;
V_42 . V_56 = V_48 ;
for (; ; ) {
V_53 = V_46 -> V_27 -> V_66 ( & V_42 , & V_50 , 1 , V_42 . V_54 ) ;
if ( V_53 != - V_58 )
break;
F_17 ( & V_42 ) ;
}
if ( - V_59 == V_53 )
V_53 = F_25 ( & V_42 ) ;
* V_30 = V_42 . V_54 ;
return V_53 ;
}
V_33 F_32 ( struct V_1 * V_1 , const char T_3 * V_47 , T_2 V_31 , T_1 * V_32 )
{
V_33 V_53 ;
if ( ! ( V_1 -> V_2 & V_67 ) )
return - V_61 ;
if ( ! V_1 -> V_27 || ( ! V_1 -> V_27 -> V_68 && ! V_1 -> V_27 -> V_66 ) )
return - V_13 ;
if ( F_13 ( ! F_27 ( V_69 , V_47 , V_31 ) ) )
return - V_64 ;
V_53 = F_12 ( V_70 , V_1 , V_32 , V_31 ) ;
if ( V_53 >= 0 ) {
V_31 = V_53 ;
if ( V_1 -> V_27 -> V_68 )
V_53 = V_1 -> V_27 -> V_68 ( V_1 , V_47 , V_31 , V_32 ) ;
else
V_53 = F_31 ( V_1 , V_47 , V_31 , V_32 ) ;
if ( V_53 > 0 ) {
F_33 ( V_1 ) ;
F_34 ( V_65 , V_53 ) ;
}
F_35 ( V_65 ) ;
}
return V_53 ;
}
static inline T_1 F_36 ( struct V_1 * V_1 )
{
return V_1 -> V_12 ;
}
static inline void F_37 ( struct V_1 * V_1 , T_1 V_32 )
{
V_1 -> V_12 = V_32 ;
}
T_4 (F_38)( unsigned int V_71 , char T_3 * V_47 ,
T_2 V_31 , T_1 V_32 )
{
struct V_1 * V_1 ;
V_33 V_53 = - V_61 ;
int V_72 ;
if ( V_32 < 0 )
return - V_13 ;
V_1 = F_39 ( V_71 , & V_72 ) ;
if ( V_1 ) {
V_53 = - V_21 ;
if ( V_1 -> V_2 & V_73 )
V_53 = F_26 ( V_1 , V_47 , V_31 , & V_32 ) ;
F_40 ( V_1 , V_72 ) ;
}
return V_53 ;
}
T_5 long F_41 ( long V_71 , long V_47 , long V_31 , T_1 V_32 )
{
return F_42 ( ( unsigned int ) V_71 , ( char T_3 * ) V_47 ,
( T_2 ) V_31 , V_32 ) ;
}
T_4 (F_43)( unsigned int V_71 , const char T_3 * V_47 ,
T_2 V_31 , T_1 V_32 )
{
struct V_1 * V_1 ;
V_33 V_53 = - V_61 ;
int V_72 ;
if ( V_32 < 0 )
return - V_13 ;
V_1 = F_39 ( V_71 , & V_72 ) ;
if ( V_1 ) {
V_53 = - V_21 ;
if ( V_1 -> V_2 & V_74 )
V_53 = F_32 ( V_1 , V_47 , V_31 , & V_32 ) ;
F_40 ( V_1 , V_72 ) ;
}
return V_53 ;
}
T_5 long F_44 ( long V_71 , long V_47 , long V_31 , T_1 V_32 )
{
return F_45 ( ( unsigned int ) V_71 , ( const char T_3 * ) V_47 ,
( T_2 ) V_31 , V_32 ) ;
}
unsigned long F_46 ( struct V_49 * V_50 , unsigned long V_75 , T_2 V_76 )
{
unsigned long V_77 = 0 ;
T_2 V_48 = 0 ;
while ( V_77 < V_75 ) {
V_77 ++ ;
if ( V_48 + V_50 -> V_52 >= V_76 ) {
V_50 -> V_52 = V_76 - V_48 ;
break;
}
V_48 += V_50 -> V_52 ;
V_50 ++ ;
}
return V_77 ;
}
V_33 F_47 ( struct V_1 * V_46 , const struct V_49 * V_50 ,
unsigned long V_75 , T_2 V_48 , T_1 * V_30 , T_6 F_11 )
{
struct V_42 V_42 ;
V_33 V_53 ;
F_24 ( & V_42 , V_46 ) ;
V_42 . V_54 = * V_30 ;
V_42 . V_55 = V_48 ;
V_42 . V_56 = V_48 ;
for (; ; ) {
V_53 = F_11 ( & V_42 , V_50 , V_75 , V_42 . V_54 ) ;
if ( V_53 != - V_58 )
break;
F_17 ( & V_42 ) ;
}
if ( V_53 == - V_59 )
V_53 = F_25 ( & V_42 ) ;
* V_30 = V_42 . V_54 ;
return V_53 ;
}
V_33 F_48 ( struct V_1 * V_46 , struct V_49 * V_50 ,
unsigned long V_75 , T_1 * V_30 , T_7 F_11 )
{
struct V_49 * V_78 = V_50 ;
V_33 V_53 = 0 ;
while ( V_75 > 0 ) {
void T_3 * V_79 ;
T_2 V_48 ;
V_33 V_80 ;
V_79 = V_78 -> V_51 ;
V_48 = V_78 -> V_52 ;
V_78 ++ ;
V_75 -- ;
V_80 = F_11 ( V_46 , V_79 , V_48 , V_30 ) ;
if ( V_80 < 0 ) {
if ( ! V_53 )
V_53 = V_80 ;
break;
}
V_53 += V_80 ;
if ( V_80 != V_48 )
break;
}
return V_53 ;
}
V_33 F_49 ( int type , const struct V_49 T_3 * V_81 ,
unsigned long V_75 , unsigned long V_82 ,
struct V_49 * V_83 ,
struct V_49 * * V_84 )
{
unsigned long V_77 ;
V_33 V_53 ;
struct V_49 * V_50 = V_83 ;
if ( V_75 == 0 ) {
V_53 = 0 ;
goto V_25;
}
if ( V_75 > V_85 ) {
V_53 = - V_13 ;
goto V_25;
}
if ( V_75 > V_82 ) {
V_50 = F_50 ( V_75 * sizeof( struct V_49 ) , V_86 ) ;
if ( V_50 == NULL ) {
V_53 = - V_87 ;
goto V_25;
}
}
if ( F_51 ( V_50 , V_81 , V_75 * sizeof( * V_81 ) ) ) {
V_53 = - V_64 ;
goto V_25;
}
V_53 = 0 ;
for ( V_77 = 0 ; V_77 < V_75 ; V_77 ++ ) {
void T_3 * V_47 = V_50 [ V_77 ] . V_51 ;
V_33 V_48 = ( V_33 ) V_50 [ V_77 ] . V_52 ;
if ( V_48 < 0 ) {
V_53 = - V_13 ;
goto V_25;
}
if ( F_13 ( ! F_27 ( F_52 ( type ) , V_47 , V_48 ) ) ) {
V_53 = - V_64 ;
goto V_25;
}
if ( V_48 > V_41 - V_53 ) {
V_48 = V_41 - V_53 ;
V_50 [ V_77 ] . V_52 = V_48 ;
}
V_53 += V_48 ;
}
V_25:
* V_84 = V_50 ;
return V_53 ;
}
static V_33 F_53 ( int type , struct V_1 * V_1 ,
const struct V_49 T_3 * V_81 ,
unsigned long V_75 , T_1 * V_32 )
{
T_2 V_88 ;
struct V_49 V_89 [ V_90 ] ;
struct V_49 * V_50 = V_89 ;
V_33 V_53 ;
T_7 F_11 ;
T_6 V_91 ;
if ( ! V_1 -> V_27 ) {
V_53 = - V_13 ;
goto V_25;
}
V_53 = F_49 ( type , V_81 , V_75 ,
F_54 ( V_89 ) , V_89 , & V_50 ) ;
if ( V_53 <= 0 )
goto V_25;
V_88 = V_53 ;
V_53 = F_12 ( type , V_1 , V_32 , V_88 ) ;
if ( V_53 < 0 )
goto V_25;
V_91 = NULL ;
if ( type == V_36 ) {
F_11 = V_1 -> V_27 -> V_62 ;
V_91 = V_1 -> V_27 -> V_57 ;
} else {
F_11 = ( T_7 ) V_1 -> V_27 -> V_68 ;
V_91 = V_1 -> V_27 -> V_66 ;
}
if ( V_91 )
V_53 = F_47 ( V_1 , V_50 , V_75 , V_88 ,
V_32 , V_91 ) ;
else
V_53 = F_48 ( V_1 , V_50 , V_75 , V_32 , F_11 ) ;
V_25:
if ( V_50 != V_89 )
F_55 ( V_50 ) ;
if ( ( V_53 + ( type == V_36 ) ) > 0 ) {
if ( type == V_36 )
F_28 ( V_1 ) ;
else
F_33 ( V_1 ) ;
}
return V_53 ;
}
V_33 F_56 ( struct V_1 * V_1 , const struct V_49 T_3 * V_92 ,
unsigned long V_93 , T_1 * V_32 )
{
if ( ! ( V_1 -> V_2 & V_60 ) )
return - V_61 ;
if ( ! V_1 -> V_27 || ( ! V_1 -> V_27 -> V_57 && ! V_1 -> V_27 -> V_62 ) )
return - V_13 ;
return F_53 ( V_36 , V_1 , V_92 , V_93 , V_32 ) ;
}
V_33 F_57 ( struct V_1 * V_1 , const struct V_49 T_3 * V_92 ,
unsigned long V_93 , T_1 * V_32 )
{
if ( ! ( V_1 -> V_2 & V_67 ) )
return - V_61 ;
if ( ! V_1 -> V_27 || ( ! V_1 -> V_27 -> V_66 && ! V_1 -> V_27 -> V_68 ) )
return - V_13 ;
return F_53 ( V_70 , V_1 , V_92 , V_93 , V_32 ) ;
}
static inline T_1 F_58 ( unsigned long V_94 , unsigned long V_95 )
{
#define F_59 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_94 << F_59 ) << F_59 ) | V_95 ;
}
static V_33 F_60 ( int V_96 , int V_97 , T_1 * V_30 ,
T_2 V_31 , T_1 V_98 )
{
struct V_1 * V_99 , * V_100 ;
struct V_6 * V_101 , * V_102 ;
T_1 V_32 ;
V_33 V_22 ;
int V_103 , V_104 , V_105 ;
V_22 = - V_61 ;
V_99 = F_39 ( V_97 , & V_103 ) ;
if ( ! V_99 )
goto V_25;
if ( ! ( V_99 -> V_2 & V_60 ) )
goto V_106;
V_22 = - V_21 ;
if ( ! V_30 )
V_30 = & V_99 -> V_12 ;
else
if ( ! ( V_99 -> V_2 & V_73 ) )
goto V_106;
V_22 = F_12 ( V_36 , V_99 , V_30 , V_31 ) ;
if ( V_22 < 0 )
goto V_106;
V_31 = V_22 ;
V_22 = - V_61 ;
V_100 = F_39 ( V_96 , & V_104 ) ;
if ( ! V_100 )
goto V_106;
if ( ! ( V_100 -> V_2 & V_67 ) )
goto V_107;
V_22 = - V_13 ;
V_101 = V_99 -> V_23 . V_24 -> V_19 ;
V_102 = V_100 -> V_23 . V_24 -> V_19 ;
V_22 = F_12 ( V_70 , V_100 , & V_100 -> V_12 , V_31 ) ;
if ( V_22 < 0 )
goto V_107;
V_31 = V_22 ;
if ( ! V_98 )
V_98 = F_61 ( V_101 -> V_14 -> V_15 , V_102 -> V_14 -> V_15 ) ;
V_32 = * V_30 ;
if ( F_13 ( V_32 + V_31 > V_98 ) ) {
V_22 = - V_34 ;
if ( V_32 >= V_98 )
goto V_107;
V_31 = V_98 - V_32 ;
}
V_105 = 0 ;
#if 0
if (in_file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
V_22 = F_62 ( V_99 , V_30 , V_100 , V_31 , V_105 ) ;
if ( V_22 > 0 ) {
F_29 ( V_65 , V_22 ) ;
F_34 ( V_65 , V_22 ) ;
}
F_30 ( V_65 ) ;
F_35 ( V_65 ) ;
if ( * V_30 > V_98 )
V_22 = - V_34 ;
V_107:
F_40 ( V_100 , V_104 ) ;
V_106:
F_40 ( V_99 , V_103 ) ;
V_25:
return V_22 ;
}
