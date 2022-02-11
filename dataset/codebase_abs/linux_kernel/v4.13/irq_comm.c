static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_7 * V_8 = V_3 -> V_9 . V_10 ;
return F_2 ( V_8 , V_2 -> V_11 . V_12 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_13 * V_14 = V_3 -> V_9 . V_15 ;
return F_4 ( V_14 , V_2 -> V_11 . V_12 , V_4 , V_5 ,
V_6 ) ;
}
int F_5 ( struct V_3 * V_3 , struct V_16 * V_17 ,
struct V_18 * V_19 , struct V_20 * V_20 )
{
int V_21 , V_22 = - 1 ;
struct V_23 * V_24 , * V_25 = NULL ;
unsigned long V_26 [ F_6 ( V_27 ) ] ;
unsigned int V_28 = 0 ;
if ( V_19 -> V_29 == 0 && V_19 -> V_30 == 0xff &&
F_7 ( V_19 ) ) {
F_8 ( V_31 L_1 ) ;
V_19 -> V_32 = V_33 ;
}
if ( F_9 ( V_3 , V_17 , V_19 , & V_22 , V_20 ) )
return V_22 ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
F_10 (i, vcpu, kvm) {
if ( ! F_11 ( V_24 ) )
continue;
if ( ! F_12 ( V_24 , V_17 , V_19 -> V_34 ,
V_19 -> V_30 , V_19 -> V_29 ) )
continue;
if ( ! F_7 ( V_19 ) ) {
if ( V_22 < 0 )
V_22 = 0 ;
V_22 += F_13 ( V_24 , V_19 , V_20 ) ;
} else if ( F_14 ( V_24 ) ) {
if ( ! F_15 () ) {
if ( ! V_25 )
V_25 = V_24 ;
else if ( F_16 ( V_24 , V_25 ) < 0 )
V_25 = V_24 ;
} else {
F_17 ( V_21 , V_26 ) ;
V_28 ++ ;
}
}
}
if ( V_28 != 0 ) {
int V_35 = F_18 ( V_19 -> V_36 , V_28 ,
V_26 , V_27 ) ;
V_25 = F_19 ( V_3 , V_35 ) ;
}
if ( V_25 )
V_22 = F_13 ( V_25 , V_19 , V_20 ) ;
return V_22 ;
}
void F_20 ( struct V_3 * V_3 , struct V_1 * V_2 ,
struct V_18 * V_19 )
{
F_21 ( V_2 -> V_37 . V_38 | ( V_3 -> V_9 . V_39 ?
( V_40 ) V_2 -> V_37 . V_41 << 32 : 0 ) ,
V_2 -> V_37 . V_42 ) ;
V_19 -> V_30 = ( V_2 -> V_37 . V_38 &
V_43 ) >> V_44 ;
if ( V_3 -> V_9 . V_39 )
V_19 -> V_30 |= F_22 ( V_2 -> V_37 . V_41 ) ;
V_19 -> V_36 = ( V_2 -> V_37 . V_42 &
V_45 ) >> V_46 ;
V_19 -> V_29 = ( 1 << V_47 ) & V_2 -> V_37 . V_38 ;
V_19 -> V_48 = ( 1 << V_49 ) & V_2 -> V_37 . V_42 ;
V_19 -> V_32 = V_2 -> V_37 . V_42 & 0x700 ;
V_19 -> V_50 = ( ( V_2 -> V_37 . V_38
& V_51 ) > 0 ) ;
V_19 -> V_5 = 1 ;
V_19 -> V_34 = 0 ;
}
static inline bool F_23 ( struct V_3 * V_3 ,
struct V_1 * V_2 )
{
return V_3 -> V_9 . V_39 && ( V_2 -> V_37 . V_41 & 0xff ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 , bool V_6 )
{
struct V_18 V_19 ;
if ( F_23 ( V_3 , V_2 ) )
return - V_52 ;
if ( ! V_5 )
return - 1 ;
F_20 ( V_3 , V_2 , & V_19 ) ;
return F_5 ( V_3 , NULL , & V_19 , NULL ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
if ( ! V_5 )
return - 1 ;
return F_26 ( V_3 , V_2 -> V_53 . V_24 , V_2 -> V_53 . V_54 ) ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_18 V_19 ;
int V_22 ;
switch ( V_2 -> type ) {
case V_55 :
return F_25 ( V_2 , V_3 , V_4 , V_5 ,
V_6 ) ;
case V_56 :
if ( F_23 ( V_3 , V_2 ) )
return - V_52 ;
F_20 ( V_3 , V_2 , & V_19 ) ;
if ( F_9 ( V_3 , NULL , & V_19 , & V_22 , NULL ) )
return V_22 ;
break;
default:
break;
}
return - V_57 ;
}
int F_28 ( struct V_3 * V_3 )
{
unsigned long * V_58 = & V_3 -> V_9 . V_59 ;
int V_4 ;
F_29 ( & V_3 -> V_60 ) ;
V_4 = F_30 ( V_58 , V_61 ) ;
if ( V_4 >= V_61 ) {
F_8 ( V_62 L_2 ) ;
V_4 = - V_63 ;
goto V_64;
}
ASSERT ( V_4 != V_65 ) ;
ASSERT ( V_4 != V_66 ) ;
F_31 ( V_4 , V_58 ) ;
V_64:
F_32 ( & V_3 -> V_60 ) ;
return V_4 ;
}
void F_33 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_65 ) ;
ASSERT ( V_4 != V_66 ) ;
F_29 ( & V_3 -> V_60 ) ;
if ( V_4 < 0 ||
V_4 >= V_61 ) {
F_8 ( V_67 L_3 ) ;
goto V_64;
}
F_34 ( V_4 , & V_3 -> V_9 . V_59 ) ;
if ( ! F_35 ( V_3 ) )
goto V_64;
F_36 ( V_3 -> V_9 . V_15 , V_4 ) ;
F_37 ( V_3 -> V_9 . V_10 , V_4 ) ;
V_64:
F_32 ( & V_3 -> V_60 ) ;
}
void F_38 ( struct V_3 * V_3 , int V_19 ,
struct V_68 * V_69 )
{
F_29 ( & V_3 -> V_60 ) ;
V_69 -> V_19 = V_19 ;
F_39 ( & V_69 -> V_70 , & V_3 -> V_9 . V_71 ) ;
F_32 ( & V_3 -> V_60 ) ;
}
void F_40 ( struct V_3 * V_3 , int V_19 ,
struct V_68 * V_69 )
{
F_29 ( & V_3 -> V_60 ) ;
F_41 ( & V_69 -> V_70 ) ;
F_32 ( & V_3 -> V_60 ) ;
F_42 ( & V_3 -> V_72 ) ;
}
void F_43 ( struct V_3 * V_3 , unsigned V_11 , unsigned V_12 ,
bool V_73 )
{
struct V_68 * V_69 ;
int V_35 , V_74 ;
V_35 = F_44 ( & V_3 -> V_72 ) ;
V_74 = F_45 ( V_3 , V_11 , V_12 ) ;
if ( V_74 != - 1 )
F_46 (kimn, &kvm->arch.mask_notifier_list, link)
if ( V_69 -> V_19 == V_74 )
V_69 -> V_75 ( V_69 , V_73 ) ;
F_47 ( & V_3 -> V_72 , V_35 ) ;
}
bool F_48 ( struct V_3 * V_3 )
{
return F_49 ( V_3 ) ;
}
int F_50 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
switch ( V_77 -> type ) {
case V_78 :
if ( F_51 ( V_3 ) )
return - V_52 ;
V_2 -> V_11 . V_12 = V_77 -> V_79 . V_11 . V_12 ;
switch ( V_77 -> V_79 . V_11 . V_11 ) {
case V_80 :
V_2 -> V_11 . V_12 += V_81 / 2 ;
case V_82 :
if ( V_77 -> V_79 . V_11 . V_12 >= V_81 / 2 )
return - V_52 ;
V_2 -> V_83 = F_1 ;
break;
case V_84 :
if ( V_77 -> V_79 . V_11 . V_12 >= V_85 )
return - V_52 ;
V_2 -> V_83 = F_3 ;
break;
default:
return - V_52 ;
}
V_2 -> V_11 . V_11 = V_77 -> V_79 . V_11 . V_11 ;
break;
case V_56 :
V_2 -> V_83 = F_24 ;
V_2 -> V_37 . V_38 = V_77 -> V_79 . V_37 . V_38 ;
V_2 -> V_37 . V_41 = V_77 -> V_79 . V_37 . V_41 ;
V_2 -> V_37 . V_42 = V_77 -> V_79 . V_37 . V_42 ;
if ( F_23 ( V_3 , V_2 ) )
return - V_52 ;
break;
case V_55 :
V_2 -> V_83 = F_25 ;
V_2 -> V_53 . V_24 = V_77 -> V_79 . V_53 . V_24 ;
V_2 -> V_53 . V_54 = V_77 -> V_79 . V_53 . V_54 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
bool F_52 ( struct V_3 * V_3 , struct V_18 * V_19 ,
struct V_23 * * V_86 )
{
int V_21 , V_22 = 0 ;
struct V_23 * V_24 ;
if ( F_53 ( V_3 , V_19 , V_86 ) )
return true ;
F_10 (i, vcpu, kvm) {
if ( ! F_11 ( V_24 ) )
continue;
if ( ! F_12 ( V_24 , NULL , V_19 -> V_34 ,
V_19 -> V_30 , V_19 -> V_29 ) )
continue;
if ( ++ V_22 == 2 )
return false ;
* V_86 = V_24 ;
}
return V_22 == 1 ;
}
int F_54 ( struct V_3 * V_3 )
{
return F_55 ( V_3 , V_87 ,
F_56 ( V_87 ) , 0 ) ;
}
int F_57 ( struct V_3 * V_3 )
{
return F_55 ( V_3 , V_88 , 0 , 0 ) ;
}
void F_58 ( struct V_3 * V_3 )
{
if ( ! F_51 ( V_3 ) )
return;
F_59 ( V_3 ) ;
}
void F_60 ( struct V_23 * V_24 ,
T_1 * V_89 )
{
struct V_3 * V_3 = V_24 -> V_3 ;
struct V_1 * V_90 ;
struct V_91 * V_92 ;
T_2 V_21 , V_93 ;
int V_35 ;
V_35 = F_44 ( & V_3 -> V_72 ) ;
V_92 = F_61 ( V_3 -> V_94 , & V_3 -> V_72 ) ;
V_93 = F_62 ( T_2 , V_92 -> V_95 ,
V_3 -> V_9 . V_96 ) ;
for ( V_21 = 0 ; V_21 < V_93 ; ++ V_21 ) {
F_63 (entry, &table->map[i], link) {
struct V_18 V_19 ;
if ( V_90 -> type != V_56 )
continue;
F_20 ( V_24 -> V_3 , V_90 , & V_19 ) ;
if ( V_19 . V_5 && F_12 ( V_24 , NULL , 0 ,
V_19 . V_30 , V_19 . V_29 ) )
F_17 ( V_19 . V_36 , V_89 ) ;
}
}
F_47 ( & V_3 -> V_72 , V_35 ) ;
}
void F_64 ( struct V_3 * V_3 )
{
F_65 ( V_3 ) ;
}
