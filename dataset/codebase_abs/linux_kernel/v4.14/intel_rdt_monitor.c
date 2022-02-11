static inline struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = & V_4 [ V_2 ] ;
F_2 ( V_3 -> V_2 != V_2 ) ;
return V_3 ;
}
static T_2 F_3 ( T_1 V_2 , T_1 V_5 )
{
T_2 V_6 ;
F_4 ( V_7 , V_5 , V_2 ) ;
F_5 ( V_8 , V_6 ) ;
return V_6 ;
}
static bool F_6 ( struct V_1 * V_3 )
{
T_2 V_6 = F_3 ( V_3 -> V_2 , V_9 ) ;
return V_6 >= V_10 ;
}
void F_7 ( struct V_11 * V_12 , bool V_13 )
{
struct V_1 * V_3 ;
struct V_14 * V_15 ;
T_1 V_16 = 1 , V_17 ;
V_15 = & V_18 [ V_19 ] ;
for (; ; ) {
V_17 = F_8 ( V_12 -> V_20 , V_15 -> V_21 , V_16 ) ;
if ( V_17 >= V_15 -> V_21 )
break;
V_3 = F_1 ( V_17 ) ;
if ( V_13 || ! F_6 ( V_3 ) ) {
F_9 ( V_3 -> V_2 , V_12 -> V_20 ) ;
if ( ! -- V_3 -> V_22 ) {
V_23 -- ;
F_10 ( & V_3 -> V_24 , & V_25 ) ;
}
}
V_16 = V_17 + 1 ;
}
}
bool F_11 ( struct V_14 * V_15 , struct V_11 * V_12 )
{
return F_12 ( V_12 -> V_20 , V_15 -> V_21 ) != V_15 -> V_21 ;
}
int F_13 ( void )
{
struct V_1 * V_3 ;
F_14 ( & V_26 ) ;
if ( F_15 ( & V_25 ) )
return V_23 ? - V_27 : - V_28 ;
V_3 = F_16 ( & V_25 ,
struct V_1 , V_24 ) ;
F_17 ( & V_3 -> V_24 ) ;
return V_3 -> V_2 ;
}
static void F_18 ( struct V_1 * V_3 )
{
struct V_14 * V_15 ;
struct V_11 * V_12 ;
int V_29 ;
T_2 V_6 ;
V_15 = & V_18 [ V_19 ] ;
V_3 -> V_22 = 0 ;
V_29 = F_19 () ;
F_20 (d, &r->domains, list) {
if ( F_21 ( V_29 , & V_12 -> V_30 ) ) {
V_6 = F_3 ( V_3 -> V_2 , V_9 ) ;
if ( V_6 <= V_10 )
continue;
}
if ( ! F_11 ( V_15 , V_12 ) )
F_22 ( V_12 , V_31 ) ;
F_23 ( V_3 -> V_2 , V_12 -> V_20 ) ;
V_3 -> V_22 ++ ;
}
F_24 () ;
if ( V_3 -> V_22 )
V_23 ++ ;
else
F_10 ( & V_3 -> V_24 , & V_25 ) ;
}
void F_25 ( T_1 V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return;
F_14 ( & V_26 ) ;
V_3 = F_1 ( V_2 ) ;
if ( F_26 () )
F_18 ( V_3 ) ;
else
F_10 ( & V_3 -> V_24 , & V_25 ) ;
}
static int F_27 ( T_1 V_2 , struct V_32 * V_33 )
{
T_2 V_34 , V_35 , V_36 ;
struct V_37 * V_38 ;
V_36 = F_3 ( V_2 , V_33 -> V_39 ) ;
if ( V_36 & ( V_40 | V_41 ) ) {
V_33 -> V_6 = V_36 ;
return - V_42 ;
}
switch ( V_33 -> V_39 ) {
case V_9 :
V_33 -> V_6 += V_36 ;
return 0 ;
case V_43 :
V_38 = & V_33 -> V_12 -> V_44 [ V_2 ] ;
break;
case V_45 :
V_38 = & V_33 -> V_12 -> V_46 [ V_2 ] ;
break;
default:
return - V_42 ;
}
if ( V_33 -> V_47 ) {
V_38 -> V_48 = V_36 ;
V_38 -> V_34 = 0 ;
return 0 ;
}
V_35 = 64 - V_49 ;
V_34 = ( V_36 << V_35 ) - ( V_38 -> V_48 << V_35 ) ;
V_34 >>= V_35 ;
V_38 -> V_34 += V_34 ;
V_38 -> V_48 = V_36 ;
V_33 -> V_6 += V_38 -> V_34 ;
return 0 ;
}
void F_28 ( void * V_50 )
{
struct V_51 * V_52 , * V_3 ;
struct V_32 * V_33 = V_50 ;
struct V_53 * V_54 ;
V_52 = V_33 -> V_55 ;
if ( F_27 ( V_52 -> V_56 . V_2 , V_33 ) )
return;
V_54 = & V_52 -> V_56 . V_57 ;
if ( V_52 -> type == V_58 ) {
F_20 (entry, head, mon.crdtgrp_list) {
if ( F_27 ( V_3 -> V_56 . V_2 , V_33 ) )
return;
}
}
}
static void F_29 ( struct V_11 * V_12 , int V_2 )
{
struct V_32 V_33 ;
V_33 . V_47 = false ;
V_33 . V_12 = V_12 ;
if ( F_30 () ) {
V_33 . V_39 = V_43 ;
F_27 ( V_2 , & V_33 ) ;
}
if ( F_31 () ) {
V_33 . V_39 = V_45 ;
F_27 ( V_2 , & V_33 ) ;
}
}
void F_32 ( struct V_59 * V_60 )
{
unsigned long V_61 = F_33 ( V_31 ) ;
int V_29 = F_34 () ;
struct V_14 * V_15 ;
struct V_11 * V_12 ;
F_35 ( & V_26 ) ;
V_15 = & V_18 [ V_19 ] ;
V_12 = F_36 ( V_29 , V_15 ) ;
if ( ! V_12 ) {
F_37 ( L_1 ) ;
goto V_62;
}
F_7 ( V_12 , false ) ;
if ( F_11 ( V_15 , V_12 ) )
F_38 ( V_29 , & V_12 -> V_63 , V_61 ) ;
V_62:
F_39 ( & V_26 ) ;
}
void F_22 ( struct V_11 * V_64 , unsigned long V_65 )
{
unsigned long V_61 = F_33 ( V_65 ) ;
struct V_14 * V_15 ;
int V_29 ;
V_15 = & V_18 [ V_19 ] ;
V_29 = F_40 ( & V_64 -> V_30 ) ;
V_64 -> V_66 = V_29 ;
F_38 ( V_29 , & V_64 -> V_63 , V_61 ) ;
}
void F_41 ( struct V_59 * V_60 )
{
unsigned long V_61 = F_33 ( V_67 ) ;
struct V_51 * V_68 , * V_69 ;
int V_29 = F_34 () ;
struct V_53 * V_54 ;
struct V_11 * V_12 ;
F_35 ( & V_26 ) ;
if ( ! F_42 ( & V_70 ) )
goto V_62;
V_12 = F_36 ( V_29 , & V_18 [ V_19 ] ) ;
if ( ! V_12 )
goto V_62;
F_20 (prgrp, &rdt_all_groups, rdtgroup_list) {
F_29 ( V_12 , V_68 -> V_56 . V_2 ) ;
V_54 = & V_68 -> V_56 . V_57 ;
F_20 (crgrp, head, mon.crdtgrp_list)
F_29 ( V_12 , V_69 -> V_56 . V_2 ) ;
}
F_38 ( V_29 , & V_12 -> V_71 , V_61 ) ;
V_62:
F_39 ( & V_26 ) ;
}
void F_43 ( struct V_11 * V_64 , unsigned long V_65 )
{
unsigned long V_61 = F_33 ( V_65 ) ;
int V_29 ;
if ( ! F_42 ( & V_70 ) )
return;
V_29 = F_40 ( & V_64 -> V_30 ) ;
V_64 -> V_72 = V_29 ;
F_38 ( V_29 , & V_64 -> V_71 , V_61 ) ;
}
static int F_44 ( struct V_14 * V_15 )
{
struct V_1 * V_3 = NULL ;
int V_73 , V_74 ;
V_74 = V_15 -> V_21 ;
V_4 = F_45 ( V_74 , sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_4 )
return - V_76 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
V_3 = & V_4 [ V_73 ] ;
F_46 ( & V_3 -> V_24 ) ;
V_3 -> V_2 = V_73 ;
F_10 ( & V_3 -> V_24 , & V_25 ) ;
}
V_3 = F_1 ( 0 ) ;
F_17 ( & V_3 -> V_24 ) ;
return 0 ;
}
static void F_47 ( struct V_14 * V_15 )
{
F_46 ( & V_15 -> V_77 ) ;
if ( F_26 () )
F_10 ( & V_78 . V_24 , & V_15 -> V_77 ) ;
if ( F_30 () )
F_10 ( & V_79 . V_24 , & V_15 -> V_77 ) ;
if ( F_31 () )
F_10 ( & V_80 . V_24 , & V_15 -> V_77 ) ;
}
int F_48 ( struct V_14 * V_15 )
{
int V_81 ;
V_15 -> V_82 = V_83 . V_84 ;
V_15 -> V_21 = V_83 . V_85 + 1 ;
V_10 = V_83 . V_86 * 1024 / V_15 -> V_21 ;
V_10 /= V_15 -> V_82 ;
V_81 = F_44 ( V_15 ) ;
if ( V_81 )
return V_81 ;
F_47 ( V_15 ) ;
V_15 -> V_87 = true ;
V_15 -> V_88 = true ;
return 0 ;
}
