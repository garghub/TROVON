static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
if ( ! V_8 )
return - 1 ;
return F_3 ( V_8 , V_2 -> V_9 . V_10 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_11 * V_12 = V_3 -> V_13 . V_14 ;
if ( ! V_12 )
return - 1 ;
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
void F_21 ( struct V_3 * V_3 , struct V_1 * V_2 ,
struct V_17 * V_18 )
{
F_22 ( V_2 -> V_36 . V_37 | ( V_3 -> V_13 . V_38 ?
( V_39 ) V_2 -> V_36 . V_40 << 32 : 0 ) ,
V_2 -> V_36 . V_41 ) ;
V_18 -> V_29 = ( V_2 -> V_36 . V_37 &
V_42 ) >> V_43 ;
if ( V_3 -> V_13 . V_38 )
V_18 -> V_29 |= F_23 ( V_2 -> V_36 . V_40 ) ;
V_18 -> V_35 = ( V_2 -> V_36 . V_41 &
V_44 ) >> V_45 ;
V_18 -> V_28 = ( 1 << V_46 ) & V_2 -> V_36 . V_37 ;
V_18 -> V_47 = ( 1 << V_48 ) & V_2 -> V_36 . V_41 ;
V_18 -> V_31 = V_2 -> V_36 . V_41 & 0x700 ;
V_18 -> V_49 = ( ( V_2 -> V_36 . V_37
& V_50 ) > 0 ) ;
V_18 -> V_5 = 1 ;
V_18 -> V_33 = 0 ;
}
static inline bool F_24 ( struct V_3 * V_3 ,
struct V_1 * V_2 )
{
return V_3 -> V_13 . V_38 && ( V_2 -> V_36 . V_40 & 0xff ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 , bool V_6 )
{
struct V_17 V_18 ;
if ( F_24 ( V_3 , V_2 ) )
return - V_51 ;
if ( ! V_5 )
return - 1 ;
F_21 ( V_3 , V_2 , & V_18 ) ;
return F_6 ( V_3 , NULL , & V_18 , NULL ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
if ( ! V_5 )
return - 1 ;
return F_27 ( V_3 , V_2 -> V_52 . V_23 , V_2 -> V_52 . V_53 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_17 V_18 ;
int V_21 ;
switch ( V_2 -> type ) {
case V_54 :
return F_26 ( V_2 , V_3 , V_4 , V_5 ,
V_6 ) ;
case V_55 :
if ( F_24 ( V_3 , V_2 ) )
return - V_51 ;
F_21 ( V_3 , V_2 , & V_18 ) ;
if ( F_10 ( V_3 , NULL , & V_18 , & V_21 , NULL ) )
return V_21 ;
break;
default:
break;
}
return - V_56 ;
}
int F_29 ( struct V_3 * V_3 )
{
unsigned long * V_57 = & V_3 -> V_13 . V_58 ;
int V_4 ;
F_30 ( & V_3 -> V_59 ) ;
V_4 = F_31 ( V_57 , V_60 ) ;
if ( V_4 >= V_60 ) {
F_9 ( V_61 L_2 ) ;
V_4 = - V_62 ;
goto V_63;
}
ASSERT ( V_4 != V_64 ) ;
ASSERT ( V_4 != V_65 ) ;
F_32 ( V_4 , V_57 ) ;
V_63:
F_33 ( & V_3 -> V_59 ) ;
return V_4 ;
}
void F_34 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_64 ) ;
ASSERT ( V_4 != V_65 ) ;
F_30 ( & V_3 -> V_59 ) ;
if ( V_4 < 0 ||
V_4 >= V_60 ) {
F_9 ( V_66 L_3 ) ;
goto V_63;
}
F_35 ( V_4 , & V_3 -> V_13 . V_58 ) ;
if ( ! F_36 ( V_3 ) )
goto V_63;
F_37 ( V_3 -> V_13 . V_14 , V_4 ) ;
F_38 ( F_2 ( V_3 ) , V_4 ) ;
V_63:
F_33 ( & V_3 -> V_59 ) ;
}
void F_39 ( struct V_3 * V_3 , int V_18 ,
struct V_67 * V_68 )
{
F_30 ( & V_3 -> V_59 ) ;
V_68 -> V_18 = V_18 ;
F_40 ( & V_68 -> V_69 , & V_3 -> V_13 . V_70 ) ;
F_33 ( & V_3 -> V_59 ) ;
}
void F_41 ( struct V_3 * V_3 , int V_18 ,
struct V_67 * V_68 )
{
F_30 ( & V_3 -> V_59 ) ;
F_42 ( & V_68 -> V_69 ) ;
F_33 ( & V_3 -> V_59 ) ;
F_43 ( & V_3 -> V_71 ) ;
}
void F_44 ( struct V_3 * V_3 , unsigned V_9 , unsigned V_10 ,
bool V_72 )
{
struct V_67 * V_68 ;
int V_34 , V_73 ;
V_34 = F_45 ( & V_3 -> V_71 ) ;
V_73 = F_46 ( V_3 , V_9 , V_10 ) ;
if ( V_73 != - 1 )
F_47 (kimn, &kvm->arch.mask_notifier_list, link)
if ( V_68 -> V_18 == V_73 )
V_68 -> V_74 ( V_68 , V_72 ) ;
F_48 ( & V_3 -> V_71 , V_34 ) ;
}
int F_49 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
const struct V_75 * V_76 )
{
int V_21 = - V_51 ;
int V_77 ;
unsigned V_78 ;
switch ( V_76 -> type ) {
case V_79 :
V_77 = 0 ;
switch ( V_76 -> V_80 . V_9 . V_9 ) {
case V_81 :
V_2 -> V_82 = F_1 ;
V_78 = V_83 ;
break;
case V_84 :
V_2 -> V_82 = F_1 ;
V_78 = V_83 ;
V_77 = 8 ;
break;
case V_85 :
V_78 = V_86 ;
V_2 -> V_82 = F_4 ;
break;
default:
goto V_87;
}
V_2 -> V_9 . V_9 = V_76 -> V_80 . V_9 . V_9 ;
V_2 -> V_9 . V_10 = V_76 -> V_80 . V_9 . V_10 + V_77 ;
if ( V_2 -> V_9 . V_10 >= V_78 )
goto V_87;
break;
case V_55 :
V_2 -> V_82 = F_25 ;
V_2 -> V_36 . V_37 = V_76 -> V_80 . V_36 . V_37 ;
V_2 -> V_36 . V_40 = V_76 -> V_80 . V_36 . V_40 ;
V_2 -> V_36 . V_41 = V_76 -> V_80 . V_36 . V_41 ;
if ( F_24 ( V_3 , V_2 ) )
goto V_87;
break;
case V_54 :
V_2 -> V_82 = F_26 ;
V_2 -> V_52 . V_23 = V_76 -> V_80 . V_52 . V_23 ;
V_2 -> V_52 . V_53 = V_76 -> V_80 . V_52 . V_53 ;
break;
default:
goto V_87;
}
V_21 = 0 ;
V_87:
return V_21 ;
}
bool F_50 ( struct V_3 * V_3 , struct V_17 * V_18 ,
struct V_22 * * V_88 )
{
int V_20 , V_21 = 0 ;
struct V_22 * V_23 ;
if ( F_51 ( V_3 , V_18 , V_88 ) )
return true ;
F_11 (i, vcpu, kvm) {
if ( ! F_12 ( V_23 ) )
continue;
if ( ! F_13 ( V_23 , NULL , V_18 -> V_33 ,
V_18 -> V_29 , V_18 -> V_28 ) )
continue;
if ( ++ V_21 == 2 )
return false ;
* V_88 = V_23 ;
}
return V_21 == 1 ;
}
int F_52 ( struct V_3 * V_3 )
{
return F_53 ( V_3 , V_89 ,
F_54 ( V_89 ) , 0 ) ;
}
int F_55 ( struct V_3 * V_3 )
{
return F_53 ( V_3 , V_90 , 0 , 0 ) ;
}
void F_56 ( struct V_3 * V_3 )
{
if ( F_36 ( V_3 ) || ! F_57 ( V_3 ) )
return;
F_58 ( V_3 ) ;
}
void F_59 ( struct V_22 * V_23 ,
T_1 * V_91 )
{
struct V_3 * V_3 = V_23 -> V_3 ;
struct V_1 * V_92 ;
struct V_93 * V_94 ;
T_2 V_20 , V_95 ;
int V_34 ;
V_34 = F_45 ( & V_3 -> V_71 ) ;
V_94 = F_60 ( V_3 -> V_96 , & V_3 -> V_71 ) ;
V_95 = F_61 ( T_2 , V_94 -> V_97 ,
V_3 -> V_13 . V_98 ) ;
for ( V_20 = 0 ; V_20 < V_95 ; ++ V_20 ) {
F_62 (entry, &table->map[i], link) {
struct V_17 V_18 ;
if ( V_92 -> type != V_55 )
continue;
F_21 ( V_23 -> V_3 , V_92 , & V_18 ) ;
if ( V_18 . V_5 && F_13 ( V_23 , NULL , 0 ,
V_18 . V_29 , V_18 . V_28 ) )
F_18 ( V_18 . V_35 , V_91 ) ;
}
}
F_48 ( & V_3 -> V_71 , V_34 ) ;
}
void F_63 ( struct V_3 * V_3 )
{
F_64 ( V_3 ) ;
}
