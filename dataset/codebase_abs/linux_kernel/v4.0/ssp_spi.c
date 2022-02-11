static struct V_1 * F_1 ( T_1 V_2 , T_2 V_3 , T_2 V_4 , T_3 V_5 )
{
struct V_6 V_7 ;
struct V_1 * V_8 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return NULL ;
V_7 . V_2 = V_2 ;
V_7 . V_10 = F_3 ( V_3 ) ;
V_7 . V_11 = F_3 ( V_4 ) ;
V_7 . V_5 = F_4 ( V_5 ) ;
V_8 -> V_12 = F_2 ( V_13 + V_3 ,
V_9 | V_14 ) ;
if ( ! V_8 -> V_12 ) {
F_5 ( V_8 ) ;
return NULL ;
}
V_8 -> V_10 = V_3 ;
V_8 -> V_11 = V_4 ;
memcpy ( V_8 -> V_12 , & V_7 , V_15 ) ;
return V_8 ;
}
static inline void F_6 ( struct V_1 * V_16 , unsigned int V_17 ,
const void * V_18 , unsigned int V_3 )
{
memcpy ( & V_16 -> V_12 [ V_13 + V_17 ] , V_18 , V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_16 , unsigned int V_17 ,
void * V_19 , unsigned int V_3 )
{
memcpy ( V_19 , & V_16 -> V_12 [ V_13 + V_17 ] , V_3 ) ;
}
static void F_8 ( struct V_1 * V_16 )
{
F_5 ( V_16 -> V_12 ) ;
F_5 ( V_16 ) ;
}
static int F_9 ( char * V_20 , int * V_21 ,
int V_22 )
{
int V_10 = V_20 [ ( * V_21 ) ++ ] ;
if ( V_10 > V_22 - * V_21 || V_10 <= 0 ) {
F_10 ( L_1 ,
V_10 , V_22 ) ;
return V_10 ? V_10 : - V_23 ;
}
F_10 ( L_2 , & V_20 [ * V_21 ] ) ;
* V_21 += V_10 ;
return 0 ;
}
static int F_11 ( struct V_24 * V_5 , bool V_25 )
{
int V_26 = 0 ;
F_12 ( V_5 -> V_27 , V_25 ) ;
while ( F_13 ( V_5 -> V_28 ) != V_25 ) {
F_14 ( 3000 , 3500 ) ;
if ( V_5 -> V_29 || V_26 ++ > 500 ) {
F_15 ( V_30 , L_3 ,
V_31 , V_25 ) ;
if ( ! V_25 )
F_12 ( V_5 -> V_27 , 1 ) ;
return - V_32 ;
}
}
return 0 ;
}
static int F_16 ( struct V_24 * V_5 , struct V_1 * V_8 ,
struct V_33 * V_34 , int V_35 )
{
int V_36 ;
const bool V_37 = V_8 -> V_10 == 0 ;
if ( V_5 -> V_29 )
return - V_38 ;
V_8 -> V_34 = V_34 ;
F_17 ( & V_5 -> V_39 ) ;
V_36 = F_11 ( V_5 , false ) ;
if ( V_36 < 0 )
goto V_40;
V_36 = F_18 ( V_5 -> V_41 , V_8 -> V_12 , V_15 ) ;
if ( V_36 < 0 ) {
F_12 ( V_5 -> V_27 , 1 ) ;
F_15 ( V_30 , L_4 , V_31 ) ;
goto V_40;
}
if ( ! V_37 ) {
F_17 ( & V_5 -> V_42 ) ;
F_19 ( & V_8 -> V_43 , & V_5 -> V_44 ) ;
F_20 ( & V_5 -> V_42 ) ;
}
V_36 = F_11 ( V_5 , true ) ;
if ( V_36 < 0 ) {
if ( ! V_37 ) {
F_17 ( & V_5 -> V_42 ) ;
F_21 ( & V_8 -> V_43 ) ;
F_20 ( & V_5 -> V_42 ) ;
}
goto V_40;
}
F_20 ( & V_5 -> V_39 ) ;
if ( ! V_37 && V_34 )
if ( F_22 ( V_34 ,
F_23 ( V_35 ) ) ==
0 ) {
F_17 ( & V_5 -> V_42 ) ;
F_21 ( & V_8 -> V_43 ) ;
F_20 ( & V_5 -> V_42 ) ;
V_5 -> V_45 ++ ;
return - V_32 ;
}
return 0 ;
V_40:
F_20 ( & V_5 -> V_39 ) ;
V_5 -> V_45 ++ ;
return V_36 ;
}
static inline int F_24 ( struct V_24 * V_5 ,
struct V_1 * V_8 )
{
return F_16 ( V_5 , V_8 , NULL , 0 ) ;
}
static int F_25 ( struct V_24 * V_5 , struct V_1 * V_8 ,
int V_35 )
{
F_26 ( V_34 ) ;
if ( F_27 ( ! V_8 -> V_10 ) )
return - V_38 ;
return F_16 ( V_5 , V_8 , & V_34 , V_35 ) ;
}
static int F_28 ( struct V_24 * V_5 , char * V_46 , int * V_47 )
{
* V_47 += 8 ;
return 0 ;
}
static int F_29 ( struct V_24 * V_5 , char * V_46 , int V_3 )
{
int V_47 , V_48 ;
struct V_49 V_50 ;
struct V_51 * V_52 ;
struct V_53 * * V_54 = V_5 -> V_55 ;
F_30 ( & V_50 ) ;
for ( V_47 = 0 ; V_47 < V_3 ; ) {
switch ( V_46 [ V_47 ++ ] ) {
case V_56 :
V_48 = V_46 [ V_47 ++ ] ;
if ( V_48 < 0 || V_48 >= V_57 ) {
F_15 ( V_30 ,
L_5 , V_48 ) ;
return - V_23 ;
}
if ( V_54 [ V_48 ] ) {
V_52 = F_31 ( V_54 [ V_48 ] ) ;
if ( V_52 -> V_58 )
V_52 -> V_58 ( V_54 [ V_48 ] ,
& V_46 [ V_47 ] ,
V_5 -> V_59 ) ;
} else {
F_15 ( V_30 , L_6 ) ;
}
V_47 += V_60 [ V_48 ] ;
break;
case V_61 :
V_48 = F_9 ( V_46 , & V_47 , V_3 ) ;
if ( V_48 ) {
F_15 ( V_30 ,
L_7 , V_48 ) ;
return V_48 ;
}
break;
case V_62 :
V_47 += V_3 ;
break;
case V_63 :
F_28 ( V_5 , V_46 , & V_47 ) ;
break;
case V_64 :
V_5 -> V_65 = true ;
break;
case V_66 :
F_32 ( V_5 , 0 ) ;
break;
}
}
if ( V_5 -> V_65 )
V_5 -> V_59 = V_50 . V_67 * 1000000000ULL + V_50 . V_68 ;
return 0 ;
}
int F_33 ( struct V_24 * V_5 )
{
bool V_69 = false ;
char * V_12 ;
T_1 V_70 ;
int V_71 ;
T_2 V_10 , V_72 ;
struct V_1 * V_8 , * V_73 ;
V_71 = F_34 ( V_5 -> V_41 , V_5 -> V_74 , V_75 ) ;
if ( V_71 < 0 ) {
F_15 ( V_30 , L_8 ) ;
return V_71 ;
}
V_10 = F_35 ( V_5 -> V_74 [ 1 ] ) ;
V_72 = F_35 ( V_5 -> V_74 [ 0 ] ) ;
if ( V_10 == 0 ) {
F_15 ( V_30 , L_9 ) ;
return - V_76 ;
}
V_70 = F_36 ( V_72 ) ;
switch ( V_70 ) {
case V_77 :
case V_78 :
F_17 ( & V_5 -> V_42 ) ;
F_37 (msg, n, &data->pending_list, list) {
if ( V_8 -> V_11 == V_72 ) {
F_21 ( & V_8 -> V_43 ) ;
V_69 = true ;
break;
}
}
if ( ! V_69 ) {
V_12 = F_38 ( V_10 , V_9 | V_14 ) ;
if ( ! V_12 ) {
V_71 = - V_79 ;
goto V_80;
}
V_71 = F_34 ( V_5 -> V_41 , V_12 , V_10 ) ;
if ( V_71 >= 0 )
V_71 = - V_23 ;
F_5 ( V_12 ) ;
F_15 ( V_30 , L_10 ,
V_72 ) ;
goto V_80;
}
if ( V_70 == V_77 )
V_71 = F_34 ( V_5 -> V_41 ,
& V_8 -> V_12 [ V_13 ] ,
V_8 -> V_10 ) ;
if ( V_70 == V_78 ) {
V_71 = F_18 ( V_5 -> V_41 ,
& V_8 -> V_12 [ V_13 ] ,
V_8 -> V_10 ) ;
if ( V_72 & V_81 ) {
V_8 -> V_11 =
V_77 | V_81 ;
V_8 -> V_10 = 1 ;
F_19 ( & V_8 -> V_43 , & V_5 -> V_44 ) ;
goto V_80;
}
}
if ( V_8 -> V_34 )
if ( ! F_39 ( V_8 -> V_34 ) )
F_40 ( V_8 -> V_34 ) ;
V_80:
F_20 ( & V_5 -> V_42 ) ;
break;
case V_82 :
V_12 = F_2 ( V_10 , V_9 | V_14 ) ;
if ( ! V_12 )
return - V_79 ;
V_71 = F_34 ( V_5 -> V_41 , V_12 , V_10 ) ;
if ( V_71 < 0 ) {
F_15 ( V_30 , L_11 ) ;
F_5 ( V_12 ) ;
break;
}
V_71 = F_29 ( V_5 , V_12 , V_10 ) ;
F_5 ( V_12 ) ;
break;
default:
F_15 ( V_30 , L_12 ) ;
return - V_23 ;
}
return V_71 ;
}
void F_41 ( struct V_24 * V_5 )
{
struct V_1 * V_8 , * V_73 ;
F_17 ( & V_5 -> V_42 ) ;
F_37 (msg, n, &data->pending_list, list) {
F_21 ( & V_8 -> V_43 ) ;
if ( V_8 -> V_34 )
if ( ! F_39 ( V_8 -> V_34 ) )
F_40 ( V_8 -> V_34 ) ;
}
F_20 ( & V_5 -> V_42 ) ;
}
int F_42 ( struct V_24 * V_5 , char V_83 , int V_84 )
{
int V_71 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_83 , 0 , V_78 , V_84 ) ;
if ( ! V_8 )
return - V_79 ;
F_10 ( L_13 , V_31 , V_83 , V_84 ) ;
V_71 = F_24 ( V_5 , V_8 ) ;
F_8 ( V_8 ) ;
return V_71 ;
}
int F_43 ( struct V_24 * V_5 , T_1 V_85 , T_1 V_86 ,
T_1 * V_87 , T_1 V_10 )
{
int V_71 ;
struct V_1 * V_8 ;
if ( V_5 -> V_88 == V_89 ) {
F_15 ( V_30 , L_14 ,
V_31 , V_5 -> V_88 ) ;
return - V_90 ;
} else if ( ! ( V_5 -> V_91 & F_44 ( V_86 ) ) &&
( V_85 <= V_92 ) ) {
F_15 ( V_30 , L_15 ,
V_31 , V_86 ) ;
return - V_93 ;
}
V_8 = F_1 ( V_85 , V_10 + 2 , V_78 , 0 ) ;
if ( ! V_8 )
return - V_79 ;
F_6 ( V_8 , 0 , & V_86 , 1 ) ;
F_6 ( V_8 , 1 , V_87 , V_10 ) ;
F_10 ( L_16 ,
V_31 , V_85 , V_86 , V_87 [ 1 ] ) ;
V_71 = F_25 ( V_5 , V_8 , 1000 ) ;
F_8 ( V_8 ) ;
return V_71 ;
}
int F_45 ( struct V_24 * V_5 )
{
int V_71 ;
char V_12 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_94 , 1 , V_77 , 0 ) ;
if ( ! V_8 )
return - V_79 ;
V_71 = F_25 ( V_5 , V_8 , 1000 ) ;
V_12 = F_46 ( V_8 , 0 ) ;
F_8 ( V_8 ) ;
return V_71 < 0 ? V_71 : V_12 ;
}
int F_47 ( struct V_24 * V_5 )
{
int V_71 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_95 ,
V_5 -> V_96 -> V_97 , V_78 ,
0 ) ;
if ( ! V_8 )
return - V_79 ;
F_6 ( V_8 , 0 , V_5 -> V_96 -> V_98 ,
V_5 -> V_96 -> V_97 ) ;
V_71 = F_25 ( V_5 , V_8 , 1000 ) ;
F_8 ( V_8 ) ;
return V_71 ;
}
unsigned int F_48 ( struct V_24 * V_5 )
{
int V_71 ;
T_4 V_99 ;
T_3 V_100 = 0 ;
struct V_1 * V_8 = F_1 ( V_101 , 4 ,
V_77 , 0 ) ;
if ( ! V_8 )
return 0 ;
V_71 = F_25 ( V_5 , V_8 , 1000 ) ;
if ( V_71 < 0 ) {
F_15 ( V_30 , L_17 , V_31 , V_71 ) ;
goto V_102;
}
F_7 ( V_8 , 0 , & V_99 , 4 ) ;
V_100 = F_49 ( V_99 ) ;
F_50 ( V_30 , L_18 , V_31 , V_100 ) ;
V_102:
F_8 ( V_8 ) ;
return V_100 ;
}
unsigned int F_51 ( struct V_24 * V_5 )
{
int V_71 ;
T_4 V_99 ;
struct V_1 * V_8 = F_1 ( V_103 , 4 ,
V_77 , 0 ) ;
if ( ! V_8 )
return V_104 ;
V_71 = F_25 ( V_5 , V_8 , 1000 ) ;
if ( V_71 < 0 ) {
F_15 ( V_30 , L_19 , V_31 , V_71 ) ;
V_71 = V_104 ;
goto V_102;
}
F_7 ( V_8 , 0 , & V_99 , 4 ) ;
V_71 = F_49 ( V_99 ) ;
V_102:
F_8 ( V_8 ) ;
return V_71 ;
}
