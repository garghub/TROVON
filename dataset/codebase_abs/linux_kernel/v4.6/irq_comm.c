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
struct V_17 * V_18 , struct V_19 * V_19 )
{
int V_20 , V_21 = - 1 ;
struct V_22 * V_23 , * V_24 = NULL ;
unsigned long V_25 [ F_7 ( V_26 ) ] ;
unsigned int V_27 = 0 ;
if ( V_18 -> V_28 == 0 && V_18 -> V_29 == 0xff &&
F_8 ( V_18 ) ) {
F_9 ( V_30 L_1 ) ;
V_18 -> V_31 = V_32 ;
}
if ( F_10 ( V_3 , V_16 , V_18 , & V_21 , V_19 ) )
return V_21 ;
memset ( V_25 , 0 , sizeof( V_25 ) ) ;
F_11 (i, vcpu, kvm) {
if ( ! F_12 ( V_23 ) )
continue;
if ( ! F_13 ( V_23 , V_16 , V_18 -> V_33 ,
V_18 -> V_29 , V_18 -> V_28 ) )
continue;
if ( ! F_8 ( V_18 ) ) {
if ( V_21 < 0 )
V_21 = 0 ;
V_21 += F_14 ( V_23 , V_18 , V_19 ) ;
} else if ( F_15 ( V_23 ) ) {
if ( ! F_16 () ) {
if ( ! V_24 )
V_24 = V_23 ;
else if ( F_17 ( V_23 , V_24 ) < 0 )
V_24 = V_23 ;
} else {
F_18 ( V_20 , V_25 ) ;
V_27 ++ ;
}
}
}
if ( V_27 != 0 ) {
int V_34 = F_19 ( V_18 -> V_35 , V_27 ,
V_25 , V_26 ) ;
V_24 = F_20 ( V_3 , V_34 ) ;
}
if ( V_24 )
V_21 = F_14 ( V_24 , V_18 , V_19 ) ;
return V_21 ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
F_22 ( V_2 -> V_36 . V_37 , V_2 -> V_36 . V_38 ) ;
V_18 -> V_29 = ( V_2 -> V_36 . V_37 &
V_39 ) >> V_40 ;
V_18 -> V_35 = ( V_2 -> V_36 . V_38 &
V_41 ) >> V_42 ;
V_18 -> V_28 = ( 1 << V_43 ) & V_2 -> V_36 . V_37 ;
V_18 -> V_44 = ( 1 << V_45 ) & V_2 -> V_36 . V_38 ;
V_18 -> V_31 = V_2 -> V_36 . V_38 & 0x700 ;
V_18 -> V_46 = ( ( V_2 -> V_36 . V_37
& V_47 ) > 0 ) ;
V_18 -> V_5 = 1 ;
V_18 -> V_33 = 0 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 , bool V_6 )
{
struct V_17 V_18 ;
if ( ! V_5 )
return - 1 ;
F_21 ( V_2 , & V_18 ) ;
return F_6 ( V_3 , NULL , & V_18 , NULL ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_17 V_18 ;
int V_21 ;
if ( F_25 ( V_2 -> type != V_48 ) )
return - V_49 ;
F_21 ( V_2 , & V_18 ) ;
if ( F_10 ( V_3 , NULL , & V_18 , & V_21 , NULL ) )
return V_21 ;
else
return - V_49 ;
}
int F_26 ( struct V_3 * V_3 )
{
unsigned long * V_50 = & V_3 -> V_13 . V_51 ;
int V_4 ;
F_27 ( & V_3 -> V_52 ) ;
V_4 = F_28 ( V_50 , V_53 ) ;
if ( V_4 >= V_53 ) {
F_9 ( V_54 L_2 ) ;
V_4 = - V_55 ;
goto V_56;
}
ASSERT ( V_4 != V_57 ) ;
ASSERT ( V_4 != V_58 ) ;
F_29 ( V_4 , V_50 ) ;
V_56:
F_30 ( & V_3 -> V_52 ) ;
return V_4 ;
}
void F_31 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_57 ) ;
ASSERT ( V_4 != V_58 ) ;
F_27 ( & V_3 -> V_52 ) ;
if ( V_4 < 0 ||
V_4 >= V_53 ) {
F_9 ( V_59 L_3 ) ;
goto V_56;
}
F_32 ( V_4 , & V_3 -> V_13 . V_51 ) ;
if ( ! F_33 ( V_3 ) )
goto V_56;
F_34 ( V_3 -> V_13 . V_14 , V_4 ) ;
F_35 ( F_2 ( V_3 ) , V_4 ) ;
V_56:
F_30 ( & V_3 -> V_52 ) ;
}
void F_36 ( struct V_3 * V_3 , int V_18 ,
struct V_60 * V_61 )
{
F_27 ( & V_3 -> V_52 ) ;
V_61 -> V_18 = V_18 ;
F_37 ( & V_61 -> V_62 , & V_3 -> V_13 . V_63 ) ;
F_30 ( & V_3 -> V_52 ) ;
}
void F_38 ( struct V_3 * V_3 , int V_18 ,
struct V_60 * V_61 )
{
F_27 ( & V_3 -> V_52 ) ;
F_39 ( & V_61 -> V_62 ) ;
F_30 ( & V_3 -> V_52 ) ;
F_40 ( & V_3 -> V_64 ) ;
}
void F_41 ( struct V_3 * V_3 , unsigned V_9 , unsigned V_10 ,
bool V_65 )
{
struct V_60 * V_61 ;
int V_34 , V_66 ;
V_34 = F_42 ( & V_3 -> V_64 ) ;
V_66 = F_43 ( V_3 , V_9 , V_10 ) ;
if ( V_66 != - 1 )
F_44 (kimn, &kvm->arch.mask_notifier_list, link)
if ( V_61 -> V_18 == V_66 )
V_61 -> V_67 ( V_61 , V_65 ) ;
F_45 ( & V_3 -> V_64 , V_34 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
if ( ! V_5 )
return - 1 ;
return F_47 ( V_3 , V_2 -> V_68 . V_23 , V_2 -> V_68 . V_69 ) ;
}
int F_48 ( struct V_1 * V_2 ,
const struct V_70 * V_71 )
{
int V_21 = - V_72 ;
int V_73 ;
unsigned V_74 ;
switch ( V_71 -> type ) {
case V_75 :
V_73 = 0 ;
switch ( V_71 -> V_76 . V_9 . V_9 ) {
case V_77 :
V_2 -> V_78 = F_1 ;
V_74 = V_79 ;
break;
case V_80 :
V_2 -> V_78 = F_1 ;
V_74 = V_79 ;
V_73 = 8 ;
break;
case V_81 :
V_74 = V_82 ;
V_2 -> V_78 = F_4 ;
break;
default:
goto V_83;
}
V_2 -> V_9 . V_9 = V_71 -> V_76 . V_9 . V_9 ;
V_2 -> V_9 . V_10 = V_71 -> V_76 . V_9 . V_10 + V_73 ;
if ( V_2 -> V_9 . V_10 >= V_74 )
goto V_83;
break;
case V_48 :
V_2 -> V_78 = F_23 ;
V_2 -> V_36 . V_37 = V_71 -> V_76 . V_36 . V_37 ;
V_2 -> V_36 . V_84 = V_71 -> V_76 . V_36 . V_84 ;
V_2 -> V_36 . V_38 = V_71 -> V_76 . V_36 . V_38 ;
break;
case V_85 :
V_2 -> V_78 = F_46 ;
V_2 -> V_68 . V_23 = V_71 -> V_76 . V_68 . V_23 ;
V_2 -> V_68 . V_69 = V_71 -> V_76 . V_68 . V_69 ;
break;
default:
goto V_83;
}
V_21 = 0 ;
V_83:
return V_21 ;
}
bool F_49 ( struct V_3 * V_3 , struct V_17 * V_18 ,
struct V_22 * * V_86 )
{
int V_20 , V_21 = 0 ;
struct V_22 * V_23 ;
if ( F_50 ( V_3 , V_18 , V_86 ) )
return true ;
F_11 (i, vcpu, kvm) {
if ( ! F_12 ( V_23 ) )
continue;
if ( ! F_13 ( V_23 , NULL , V_18 -> V_33 ,
V_18 -> V_29 , V_18 -> V_28 ) )
continue;
if ( ++ V_21 == 2 )
return false ;
* V_86 = V_23 ;
}
return V_21 == 1 ;
}
int F_51 ( struct V_3 * V_3 )
{
return F_52 ( V_3 , V_87 ,
F_53 ( V_87 ) , 0 ) ;
}
int F_54 ( struct V_3 * V_3 )
{
return F_52 ( V_3 , V_88 , 0 , 0 ) ;
}
void F_55 ( struct V_3 * V_3 )
{
if ( F_33 ( V_3 ) || ! F_56 ( V_3 ) )
return;
F_57 ( V_3 ) ;
}
void F_58 ( struct V_22 * V_23 ,
T_1 * V_89 )
{
struct V_3 * V_3 = V_23 -> V_3 ;
struct V_1 * V_90 ;
struct V_91 * V_92 ;
T_2 V_20 , V_93 ;
int V_34 ;
F_59 () ;
V_34 = F_42 ( & V_3 -> V_64 ) ;
V_92 = F_60 ( V_3 -> V_94 , & V_3 -> V_64 ) ;
V_93 = F_61 ( T_2 , V_92 -> V_95 ,
V_3 -> V_13 . V_96 ) ;
for ( V_20 = 0 ; V_20 < V_93 ; ++ V_20 ) {
F_62 (entry, &table->map[i], link) {
T_2 V_29 , V_28 ;
bool V_5 ;
if ( V_90 -> type != V_48 )
continue;
V_29 = ( V_90 -> V_36 . V_37 >> 12 ) & 0xff ;
V_28 = ( V_90 -> V_36 . V_37 >> 2 ) & 0x1 ;
V_5 = V_90 -> V_36 . V_38 & V_97 ;
if ( V_5 && F_13 ( V_23 , NULL , 0 ,
V_29 , V_28 ) ) {
T_2 V_35 = V_90 -> V_36 . V_38 & 0xff ;
F_18 ( V_35 ,
V_89 ) ;
}
}
}
F_45 ( & V_3 -> V_64 , V_34 ) ;
}
int F_63 ( struct V_1 * V_18 , struct V_3 * V_3 ,
int V_4 , int V_5 , bool V_6 )
{
switch ( V_18 -> type ) {
case V_85 :
return F_46 ( V_18 , V_3 , V_4 , V_5 ,
V_6 ) ;
default:
return - V_49 ;
}
}
void F_64 ( struct V_3 * V_3 )
{
F_65 ( V_3 ) ;
}
