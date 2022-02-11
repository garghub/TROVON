static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 , struct V_6 * V_7 , bool V_8 )
{
T_1 V_9 = 0 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
int V_13 ;
long V_14 [ V_15 ] = { 0 } ;
long V_16 [ V_15 ] = { 0 } ;
int V_17 = 0 ;
int V_18 = 0 ;
V_9 = F_2 ( V_5 , V_19 , L_1 ) ;
if ( V_9 <= 0 )
return 0 ;
V_17 += V_9 ;
F_3 ( & V_20 . V_21 , V_12 ) ;
F_4 (bo, bo_list, list) {
if ( ( V_8 && ( V_11 -> V_22 & V_23 ) ) ||
( ! V_8 && ! ( V_11 -> V_22 & V_23 ) ) ) {
V_9 = F_2 ( V_5 + V_17 , V_19 - V_17 ,
L_2 ,
V_24 [ V_11 -> type ] , V_11 -> V_25 ) ;
V_14 [ V_11 -> type ] += V_11 -> V_25 ;
V_16 [ V_11 -> type ] ++ ;
if ( V_9 > 0 )
V_17 += V_9 ;
}
}
F_5 ( & V_20 . V_21 , V_12 ) ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
if ( V_16 [ V_13 ] ) {
V_9 = F_2 ( V_5 + V_17 + V_18 ,
V_19 - V_17 - V_18 ,
L_3 ,
V_16 [ V_13 ] , V_24 [ V_13 ] , V_14 [ V_13 ] * 4 ) ;
if ( V_9 > 0 )
V_18 += V_9 ;
}
}
return V_17 + V_18 + 1 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , & V_20 . V_26 , true ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , & V_20 . V_26 , false ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_1 V_9 = 0 ;
struct V_27 * V_28 = V_29 . V_30 ;
unsigned long V_12 ;
if ( ! V_28 || ! V_28 -> V_31 )
return 0 ;
F_3 ( & V_28 -> V_21 , V_12 ) ;
V_9 = F_2 ( V_5 , V_19 , L_4 ,
V_28 -> V_32 , V_28 -> V_25 ) ;
F_5 ( & V_28 -> V_21 , V_12 ) ;
if ( V_9 > 0 )
V_9 ++ ;
return V_9 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_1 V_9 = 0 ;
struct V_33 * V_28 = V_34 . V_30 ;
unsigned long V_12 ;
if ( ! V_28 || ! V_28 -> V_31 )
return 0 ;
F_3 ( & V_28 -> V_21 , V_12 ) ;
V_9 = F_2 ( V_5 , V_19 , L_5 ,
V_28 -> V_25 , V_28 -> V_35 ) ;
F_5 ( & V_28 -> V_21 , V_12 ) ;
if ( V_9 > 0 )
V_9 ++ ;
return V_9 ;
}
int F_10 ( void )
{
int V_9 ;
V_9 = F_11 ( & V_20 , & V_36 ,
V_37 , V_38 ) ;
if ( V_9 )
F_12 ( V_39 , L_6 ) ;
V_40 = F_13 ( 1 , V_41 , 0 , 0 , V_42 ) ;
if ( ! V_9 ) {
V_9 = F_14 ( & V_39 -> V_43 ,
V_44 ) ;
if ( V_9 )
F_12 ( V_39 ,
L_7 , V_45 ) ;
}
return V_9 ;
}
void F_15 ( void )
{
F_16 ( & V_39 -> V_43 , V_44 ) ;
F_17 ( V_40 ) ;
V_40 = 0 ;
F_18 ( & V_20 ) ;
}
T_2 F_13 ( T_3 V_46 , enum V_47 type ,
int V_48 , void * V_49 , bool V_50 )
{
unsigned int V_25 ;
struct V_10 * V_11 ;
int V_9 ;
if ( ! V_40 )
F_10 () ;
V_25 = F_19 ( V_46 ) ;
V_11 = F_20 ( & V_20 , V_25 ) ;
if ( ! V_11 ) {
F_12 ( V_39 , L_8 ) ;
goto V_51;
}
V_9 = F_21 ( V_11 , type , V_48 , V_49 , V_50 ) ;
if ( V_9 ) {
F_12 ( V_39 ,
L_9 ) ;
goto V_52;
}
V_9 = F_22 ( V_11 ) ;
if ( V_9 ) {
F_12 ( V_39 , L_10 ) ;
goto V_53;
}
V_54 . V_55 += V_25 ;
return V_11 -> V_56 ;
V_53:
F_23 ( V_11 ) ;
V_52:
F_24 ( V_11 ) ;
V_51:
return 0 ;
}
void F_17 ( T_2 V_57 )
{
struct V_10 * V_11 ;
F_25 ( ! V_57 ) ;
V_11 = F_26 ( & V_20 , ( unsigned int ) V_57 ) ;
if ( ! V_11 ) {
F_12 ( V_39 ,
L_11
L_12 , ( unsigned int ) V_57 ) ;
return;
}
V_54 . V_55 -= V_11 -> V_25 ;
F_27 ( V_11 ) ;
F_23 ( V_11 ) ;
F_24 ( V_11 ) ;
}
static inline int F_28 ( struct V_10 * V_11 , unsigned int V_58 )
{
if ( ! V_11 ) {
F_12 ( V_39 ,
L_13
L_12 , V_58 ) ;
return - V_59 ;
}
if ( ! F_29 ( V_11 ) ) {
F_12 ( V_39 ,
L_14 ) ;
return - V_59 ;
}
if ( ! F_30 ( V_11 ) ) {
F_12 ( V_39 ,
L_15
L_16 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_31 ( T_2 V_57 , void * V_60 , unsigned int V_46 )
{
struct V_10 * V_11 ;
unsigned int V_61 , V_62 , V_63 ;
char * V_64 , * V_65 ;
int V_9 ;
V_11 = F_32 ( & V_20 , V_57 ) ;
V_9 = F_28 ( V_11 , V_57 ) ;
if ( V_9 )
return V_9 ;
V_65 = ( char * ) V_60 ;
while ( V_46 ) {
V_61 = ( V_57 - V_11 -> V_56 ) >> V_66 ;
V_62 = ( V_57 - V_11 -> V_56 ) - ( V_61 << V_66 ) ;
V_64 = ( char * ) F_33 ( V_11 -> V_67 [ V_61 ] . V_68 ) + V_62 ;
if ( ( V_46 + V_62 ) >= V_19 ) {
V_63 = V_19 - V_62 ;
V_46 -= V_63 ;
} else {
V_63 = V_46 ;
V_46 = 0 ;
}
V_57 += V_63 ;
if ( V_65 ) {
memcpy ( V_65 , V_64 , V_63 ) ;
V_65 += V_63 ;
}
F_34 ( V_64 , V_63 ) ;
F_35 ( V_11 -> V_67 [ V_61 ] . V_68 ) ;
}
return 0 ;
}
static int F_36 ( T_2 V_57 , void * V_60 , unsigned int V_46 )
{
struct V_10 * V_11 ;
int V_9 ;
V_11 = F_32 ( & V_20 , V_57 ) ;
V_9 = F_28 ( V_11 , V_57 ) ;
if ( V_9 )
return V_9 ;
if ( V_11 -> V_22 & V_69 || V_11 -> V_22 & V_70 ) {
void * V_64 = V_11 -> V_71 ;
V_64 += ( V_57 - V_11 -> V_56 ) ;
memcpy ( V_60 , V_64 , V_46 ) ;
if ( V_11 -> V_22 & V_70 )
F_34 ( V_64 , V_46 ) ;
} else {
void * V_72 ;
V_72 = F_37 ( V_11 , true ) ;
if ( ! V_72 )
return F_31 ( V_57 , V_60 , V_46 ) ;
else
V_72 = V_72 + ( V_57 - V_11 -> V_56 ) ;
memcpy ( V_60 , V_72 , V_46 ) ;
F_34 ( V_72 , V_46 ) ;
F_38 ( V_11 ) ;
}
return 0 ;
}
int F_39 ( T_2 V_57 , void * V_60 , unsigned int V_46 )
{
if ( ! V_60 ) {
F_12 ( V_39 ,
L_17 ) ;
return - V_59 ;
}
return F_36 ( V_57 , V_60 , V_46 ) ;
}
int F_40 ( T_2 V_57 , unsigned int V_46 )
{
return F_36 ( V_57 , NULL , V_46 ) ;
}
int F_41 ( T_2 V_57 , const void * V_60 , unsigned int V_46 )
{
struct V_10 * V_11 ;
unsigned int V_61 , V_62 , V_63 ;
char * V_64 , * V_65 ;
int V_9 ;
V_11 = F_32 ( & V_20 , V_57 ) ;
V_9 = F_28 ( V_11 , V_57 ) ;
if ( V_9 )
return V_9 ;
if ( V_11 -> V_22 & V_69 || V_11 -> V_22 & V_70 ) {
void * V_73 = V_11 -> V_71 ;
V_73 += ( V_57 - V_11 -> V_56 ) ;
memcpy ( V_73 , V_60 , V_46 ) ;
if ( V_11 -> V_22 & V_70 )
F_34 ( V_73 , V_46 ) ;
} else {
void * V_72 ;
V_72 = F_37 ( V_11 , true ) ;
if ( V_72 ) {
V_72 = V_72 + ( V_57 - V_11 -> V_56 ) ;
memcpy ( V_72 , V_60 , V_46 ) ;
F_34 ( V_72 , V_46 ) ;
F_38 ( V_11 ) ;
return 0 ;
}
}
V_64 = ( char * ) V_60 ;
while ( V_46 ) {
V_61 = ( V_57 - V_11 -> V_56 ) >> V_66 ;
V_62 = ( V_57 - V_11 -> V_56 ) - ( V_61 << V_66 ) ;
if ( F_42 () )
V_65 = ( char * ) F_43 ( V_11 -> V_67 [ V_61 ] . V_68 ) ;
else
V_65 = ( char * ) F_33 ( V_11 -> V_67 [ V_61 ] . V_68 ) ;
if ( ! V_65 ) {
F_12 ( V_39 ,
L_18
L_19 , V_61 ) ;
return - V_59 ;
}
V_65 += V_62 ;
if ( ( V_46 + V_62 ) >= V_19 ) {
V_63 = V_19 - V_62 ;
V_46 -= V_63 ;
} else {
V_63 = V_46 ;
V_46 = 0 ;
}
V_57 += V_63 ;
memcpy ( V_65 , V_64 , V_63 ) ;
V_64 += V_63 ;
F_34 ( V_65 , V_63 ) ;
if ( F_42 () )
F_44 ( V_65 - V_62 ) ;
else
F_35 ( V_11 -> V_67 [ V_61 ] . V_68 ) ;
}
return 0 ;
}
int F_45 ( T_2 V_57 , int V_74 , unsigned int V_46 )
{
struct V_10 * V_11 ;
unsigned int V_61 , V_62 , V_63 ;
char * V_65 ;
int V_9 ;
V_11 = F_32 ( & V_20 , V_57 ) ;
V_9 = F_28 ( V_11 , V_57 ) ;
if ( V_9 )
return V_9 ;
if ( V_11 -> V_22 & V_69 || V_11 -> V_22 & V_70 ) {
void * V_73 = V_11 -> V_71 ;
V_73 += ( V_57 - V_11 -> V_56 ) ;
memset ( V_73 , V_74 , V_46 ) ;
if ( V_11 -> V_22 & V_70 )
F_34 ( V_73 , V_46 ) ;
} else {
void * V_72 ;
V_72 = F_37 ( V_11 , true ) ;
if ( V_72 ) {
V_72 = V_72 + ( V_57 - V_11 -> V_56 ) ;
memset ( V_72 , V_74 , V_46 ) ;
F_34 ( V_72 , V_46 ) ;
F_38 ( V_11 ) ;
return 0 ;
}
}
while ( V_46 ) {
V_61 = ( V_57 - V_11 -> V_56 ) >> V_66 ;
V_62 = ( V_57 - V_11 -> V_56 ) - ( V_61 << V_66 ) ;
V_65 = ( char * ) F_33 ( V_11 -> V_67 [ V_61 ] . V_68 ) + V_62 ;
if ( ( V_46 + V_62 ) >= V_19 ) {
V_63 = V_19 - V_62 ;
V_46 -= V_63 ;
} else {
V_63 = V_46 ;
V_46 = 0 ;
}
V_57 += V_63 ;
memset ( V_65 , V_74 , V_63 ) ;
F_34 ( V_65 , V_63 ) ;
F_35 ( V_11 -> V_67 [ V_61 ] . V_68 ) ;
}
return 0 ;
}
T_4 F_46 ( T_2 V_57 )
{
unsigned int V_61 , V_62 ;
struct V_10 * V_11 ;
V_11 = F_32 ( & V_20 , V_57 ) ;
if ( ! V_11 ) {
F_12 ( V_39 ,
L_20 ,
V_57 ) ;
return - 1 ;
}
V_61 = ( V_57 - V_11 -> V_56 ) >> V_66 ;
V_62 = ( V_57 - V_11 -> V_56 ) - ( V_61 << V_66 ) ;
return F_47 ( V_11 -> V_67 [ V_61 ] . V_68 ) + V_62 ;
}
int F_48 ( struct V_75 * V_76 , T_2 V_57 )
{
struct V_10 * V_11 ;
V_11 = F_26 ( & V_20 , V_57 ) ;
if ( ! V_11 ) {
F_12 ( V_39 ,
L_21 ,
V_57 ) ;
return - V_59 ;
}
return F_49 ( V_76 , V_11 ) ;
}
void * F_50 ( T_2 V_57 , bool V_50 )
{
struct V_10 * V_11 ;
void * V_58 ;
V_11 = F_32 ( & V_20 , V_57 ) ;
if ( ! V_11 ) {
F_12 ( V_39 ,
L_20 ,
V_57 ) ;
return NULL ;
}
V_58 = F_37 ( V_11 , V_50 ) ;
if ( V_58 )
return V_58 + ( V_57 - V_11 -> V_56 ) ;
else
return NULL ;
}
void F_51 ( T_2 V_57 )
{
struct V_10 * V_11 ;
V_11 = F_32 ( & V_20 , V_57 ) ;
if ( ! V_11 ) {
F_52 ( V_39 ,
L_20 ,
V_57 ) ;
return;
}
F_53 ( V_11 ) ;
}
void F_54 ( T_2 V_57 )
{
struct V_10 * V_11 ;
V_11 = F_32 ( & V_20 , V_57 ) ;
if ( ! V_11 ) {
F_52 ( V_39 ,
L_20 ,
V_57 ) ;
return;
}
return F_38 ( V_11 ) ;
}
int F_55 ( unsigned int V_35 ,
enum V_77 V_78 )
{
switch ( V_78 ) {
case V_79 :
V_29 . V_80 = & V_81 ;
return V_29 . V_80 -> V_82 ( & V_29 . V_30 ,
V_35 ) ;
case V_83 :
V_34 . V_80 = & V_84 ;
return V_34 . V_80 -> V_82 ( & V_34 . V_30 ,
V_35 ) ;
default:
F_12 ( V_39 , L_22 ) ;
return - V_59 ;
}
}
void F_56 ( enum V_77 V_78 )
{
switch ( V_78 ) {
case V_79 :
if ( V_29 . V_80 && V_29 . V_80 -> V_85 )
V_29 . V_80 -> V_85 ( & V_29 . V_30 ) ;
break;
case V_83 :
if ( V_34 . V_80 && V_34 . V_80 -> V_85 )
V_34 . V_80 -> V_85 ( & V_34 . V_30 ) ;
break;
default:
F_12 ( V_39 , L_22 ) ;
break;
}
return;
}
void * F_57 ( T_2 V_58 , bool V_50 )
{
return F_50 ( V_58 , V_50 ) ;
}
T_2 F_58 ( const void * V_58 )
{
struct V_10 * V_11 ;
V_11 = F_59 ( & V_20 , V_58 ) ;
if ( V_11 )
return V_11 -> V_56 ;
F_12 ( V_39 ,
L_23 ,
V_58 ) ;
return 0 ;
}
void F_60 ( const char * V_86 , const int line )
{
F_61 ( L_24 ,
V_54 . V_55 ,
V_54 . V_87 , V_54 . V_88 ,
V_54 . V_89 , V_54 . V_90 ,
V_54 . V_91 , V_54 . V_92 ) ;
}
void F_62 ( int V_93 , int V_94 , int V_95 )
{
V_54 . V_88 = V_93 ;
if ( 0 == V_54 . V_88 ) {
V_54 . V_88 = - 1 ;
V_54 . V_89 = - 1 ;
}
if ( ! V_94 ) {
V_54 . V_92 = - 1 ;
V_54 . V_91 = - 1 ;
} else {
V_54 . V_92 = 0 ;
V_54 . V_91 = V_95 ;
}
V_54 . V_87 = 0 ;
V_54 . V_90 = 0 ;
V_54 . V_55 = 0 ;
}
