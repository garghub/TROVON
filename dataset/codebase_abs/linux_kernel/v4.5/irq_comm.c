static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
return F_3 ( V_8 , V_2 -> V_9 . V_10 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_11 * V_12 = V_3 -> V_13 . V_14 ;
return F_5 ( V_12 , V_2 -> V_9 . V_10 , V_4 , V_5 ,
V_6 ) ;
}
int F_6 ( struct V_3 * V_3 , struct V_15 * V_16 ,
struct V_17 * V_18 , unsigned long * V_19 )
{
int V_20 , V_21 = - 1 ;
struct V_22 * V_23 , * V_24 = NULL ;
if ( V_18 -> V_25 == 0 && V_18 -> V_26 == 0xff &&
F_7 ( V_18 ) ) {
F_8 ( V_27 L_1 ) ;
V_18 -> V_28 = V_29 ;
}
if ( F_9 ( V_3 , V_16 , V_18 , & V_21 , V_19 ) )
return V_21 ;
F_10 (i, vcpu, kvm) {
if ( ! F_11 ( V_23 ) )
continue;
if ( ! F_12 ( V_23 , V_16 , V_18 -> V_30 ,
V_18 -> V_26 , V_18 -> V_25 ) )
continue;
if ( ! F_7 ( V_18 ) ) {
if ( V_21 < 0 )
V_21 = 0 ;
V_21 += F_13 ( V_23 , V_18 , V_19 ) ;
} else if ( F_14 ( V_23 ) ) {
if ( ! V_24 )
V_24 = V_23 ;
else if ( F_15 ( V_23 , V_24 ) < 0 )
V_24 = V_23 ;
}
}
if ( V_24 )
V_21 = F_13 ( V_24 , V_18 , V_19 ) ;
return V_21 ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
F_17 ( V_2 -> V_31 . V_32 , V_2 -> V_31 . V_33 ) ;
V_18 -> V_26 = ( V_2 -> V_31 . V_32 &
V_34 ) >> V_35 ;
V_18 -> V_36 = ( V_2 -> V_31 . V_33 &
V_37 ) >> V_38 ;
V_18 -> V_25 = ( 1 << V_39 ) & V_2 -> V_31 . V_32 ;
V_18 -> V_40 = ( 1 << V_41 ) & V_2 -> V_31 . V_33 ;
V_18 -> V_28 = V_2 -> V_31 . V_33 & 0x700 ;
V_18 -> V_42 = ( ( V_2 -> V_31 . V_32
& V_43 ) > 0 ) ;
V_18 -> V_5 = 1 ;
V_18 -> V_30 = 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 , bool V_6 )
{
struct V_17 V_18 ;
if ( ! V_5 )
return - 1 ;
F_16 ( V_2 , & V_18 ) ;
return F_6 ( V_3 , NULL , & V_18 , NULL ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_17 V_18 ;
int V_21 ;
if ( F_20 ( V_2 -> type != V_44 ) )
return - V_45 ;
F_16 ( V_2 , & V_18 ) ;
if ( F_9 ( V_3 , NULL , & V_18 , & V_21 , NULL ) )
return V_21 ;
else
return - V_45 ;
}
int F_21 ( struct V_3 * V_3 )
{
unsigned long * V_46 = & V_3 -> V_13 . V_47 ;
int V_4 ;
F_22 ( & V_3 -> V_48 ) ;
V_4 = F_23 ( V_46 , V_49 ) ;
if ( V_4 >= V_49 ) {
F_8 ( V_50 L_2 ) ;
V_4 = - V_51 ;
goto V_52;
}
ASSERT ( V_4 != V_53 ) ;
ASSERT ( V_4 != V_54 ) ;
F_24 ( V_4 , V_46 ) ;
V_52:
F_25 ( & V_3 -> V_48 ) ;
return V_4 ;
}
void F_26 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_53 ) ;
ASSERT ( V_4 != V_54 ) ;
F_22 ( & V_3 -> V_48 ) ;
if ( V_4 < 0 ||
V_4 >= V_49 ) {
F_8 ( V_55 L_3 ) ;
goto V_52;
}
F_27 ( V_4 , & V_3 -> V_13 . V_47 ) ;
if ( ! F_28 ( V_3 ) )
goto V_52;
F_29 ( V_3 -> V_13 . V_14 , V_4 ) ;
F_30 ( F_2 ( V_3 ) , V_4 ) ;
V_52:
F_25 ( & V_3 -> V_48 ) ;
}
void F_31 ( struct V_3 * V_3 , int V_18 ,
struct V_56 * V_57 )
{
F_22 ( & V_3 -> V_48 ) ;
V_57 -> V_18 = V_18 ;
F_32 ( & V_57 -> V_58 , & V_3 -> V_13 . V_59 ) ;
F_25 ( & V_3 -> V_48 ) ;
}
void F_33 ( struct V_3 * V_3 , int V_18 ,
struct V_56 * V_57 )
{
F_22 ( & V_3 -> V_48 ) ;
F_34 ( & V_57 -> V_58 ) ;
F_25 ( & V_3 -> V_48 ) ;
F_35 ( & V_3 -> V_60 ) ;
}
void F_36 ( struct V_3 * V_3 , unsigned V_9 , unsigned V_10 ,
bool V_61 )
{
struct V_56 * V_57 ;
int V_62 , V_63 ;
V_62 = F_37 ( & V_3 -> V_60 ) ;
V_63 = F_38 ( V_3 , V_9 , V_10 ) ;
if ( V_63 != - 1 )
F_39 (kimn, &kvm->arch.mask_notifier_list, link)
if ( V_57 -> V_18 == V_63 )
V_57 -> V_64 ( V_57 , V_61 ) ;
F_40 ( & V_3 -> V_60 , V_62 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
if ( ! V_5 )
return - 1 ;
return F_42 ( V_3 , V_2 -> V_65 . V_23 , V_2 -> V_65 . V_66 ) ;
}
int F_43 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
int V_21 = - V_69 ;
int V_70 ;
unsigned V_71 ;
switch ( V_68 -> type ) {
case V_72 :
V_70 = 0 ;
switch ( V_68 -> V_73 . V_9 . V_9 ) {
case V_74 :
V_2 -> V_75 = F_1 ;
V_71 = V_76 ;
break;
case V_77 :
V_2 -> V_75 = F_1 ;
V_71 = V_76 ;
V_70 = 8 ;
break;
case V_78 :
V_71 = V_79 ;
V_2 -> V_75 = F_4 ;
break;
default:
goto V_80;
}
V_2 -> V_9 . V_9 = V_68 -> V_73 . V_9 . V_9 ;
V_2 -> V_9 . V_10 = V_68 -> V_73 . V_9 . V_10 + V_70 ;
if ( V_2 -> V_9 . V_10 >= V_71 )
goto V_80;
break;
case V_44 :
V_2 -> V_75 = F_18 ;
V_2 -> V_31 . V_32 = V_68 -> V_73 . V_31 . V_32 ;
V_2 -> V_31 . V_81 = V_68 -> V_73 . V_31 . V_81 ;
V_2 -> V_31 . V_33 = V_68 -> V_73 . V_31 . V_33 ;
break;
case V_82 :
V_2 -> V_75 = F_41 ;
V_2 -> V_65 . V_23 = V_68 -> V_73 . V_65 . V_23 ;
V_2 -> V_65 . V_66 = V_68 -> V_73 . V_65 . V_66 ;
break;
default:
goto V_80;
}
V_21 = 0 ;
V_80:
return V_21 ;
}
bool F_44 ( struct V_3 * V_3 , struct V_17 * V_18 ,
struct V_22 * * V_83 )
{
int V_20 , V_21 = 0 ;
struct V_22 * V_23 ;
if ( F_45 ( V_3 , V_18 , V_83 ) )
return true ;
F_10 (i, vcpu, kvm) {
if ( ! F_11 ( V_23 ) )
continue;
if ( ! F_12 ( V_23 , NULL , V_18 -> V_30 ,
V_18 -> V_26 , V_18 -> V_25 ) )
continue;
if ( ++ V_21 == 2 )
return false ;
* V_83 = V_23 ;
}
return V_21 == 1 ;
}
int F_46 ( struct V_3 * V_3 )
{
return F_47 ( V_3 , V_84 ,
F_48 ( V_84 ) , 0 ) ;
}
int F_49 ( struct V_3 * V_3 )
{
return F_47 ( V_3 , V_85 , 0 , 0 ) ;
}
void F_50 ( struct V_3 * V_3 )
{
if ( F_28 ( V_3 ) || ! F_51 ( V_3 ) )
return;
F_52 ( V_3 ) ;
}
void F_53 ( struct V_22 * V_23 ,
T_1 * V_86 )
{
struct V_3 * V_3 = V_23 -> V_3 ;
struct V_1 * V_87 ;
struct V_88 * V_89 ;
T_2 V_20 , V_90 ;
int V_62 ;
F_54 () ;
V_62 = F_37 ( & V_3 -> V_60 ) ;
V_89 = F_55 ( V_3 -> V_91 , & V_3 -> V_60 ) ;
V_90 = F_56 ( T_2 , V_89 -> V_92 ,
V_3 -> V_13 . V_93 ) ;
for ( V_20 = 0 ; V_20 < V_90 ; ++ V_20 ) {
F_57 (entry, &table->map[i], link) {
T_2 V_26 , V_25 ;
bool V_5 ;
if ( V_87 -> type != V_44 )
continue;
V_26 = ( V_87 -> V_31 . V_32 >> 12 ) & 0xff ;
V_25 = ( V_87 -> V_31 . V_32 >> 2 ) & 0x1 ;
V_5 = V_87 -> V_31 . V_33 & V_94 ;
if ( V_5 && F_12 ( V_23 , NULL , 0 ,
V_26 , V_25 ) ) {
T_2 V_36 = V_87 -> V_31 . V_33 & 0xff ;
F_58 ( V_36 ,
V_86 ) ;
}
}
}
F_40 ( & V_3 -> V_60 , V_62 ) ;
}
int F_59 ( struct V_1 * V_18 , struct V_3 * V_3 ,
int V_4 , int V_5 , bool V_6 )
{
switch ( V_18 -> type ) {
case V_82 :
return F_41 ( V_18 , V_3 , V_4 , V_5 ,
V_6 ) ;
default:
return - V_45 ;
}
}
void F_60 ( struct V_3 * V_3 )
{
F_61 ( V_3 ) ;
}
