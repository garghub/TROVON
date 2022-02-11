static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 , V_8 , V_9 ;
char * V_10 , * type ;
F_2 ( V_2 -> V_11 , L_1 , V_12 ) ;
V_4 -> V_13 = F_3 ( & V_6 -> V_14 ) ;
V_4 -> V_15 = F_4 ( & V_6 -> V_14 ) ? 1 : 0 ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = F_5 ( & V_6 -> V_14 ) ;
F_6 ( & V_4 -> V_19 ) ;
F_6 ( & V_4 -> V_20 ) ;
V_7 = F_7 ( V_2 , V_6 -> V_21 ) ;
F_8 ( V_2 , V_6 -> V_21 , & V_8 , & V_9 ) ;
if ( ( V_7 == V_22 || V_7 == V_23 ) &&
V_8 != 0 && V_8 != 1 ) {
F_2 ( V_2 -> V_11 ,
L_2 ,
F_9 ( & V_6 -> V_14 ) , V_8 ,
V_9 ) ;
V_4 -> V_24 = 1 ;
}
if ( V_4 -> V_13 == V_25 ||
V_4 -> V_13 == V_26 ) {
T_1 V_27 , V_28 ;
int V_29 =
F_10 ( V_4 -> V_18 ) * F_11 ( V_4 -> V_18 ) ;
V_4 -> V_30 = F_12 ( F_13 ( V_4 -> V_24 ?
V_31 : V_7 , V_4 -> V_15 ,
V_4 -> V_13 == V_26 ,
V_29 ) ) ;
V_4 -> V_32 = F_14 ( V_2 -> V_33 ,
V_34 ) ;
V_4 -> V_35 = V_6 -> V_35 ;
#if 0
if (qh->ep_type == USB_ENDPOINT_XFER_INT)
qh->interval = 8;
#endif
V_27 = F_15 ( V_2 -> V_36 + V_37 ) ;
V_28 = ( V_27 & V_38 ) >> V_39 ;
if ( V_28 == V_40 &&
( V_7 == V_22 ||
V_7 == V_23 ) ) {
V_4 -> V_35 *= 8 ;
V_4 -> V_32 |= 0x7 ;
V_4 -> V_41 = V_4 -> V_32 ;
}
F_16 ( V_2 -> V_11 , L_3 , V_4 -> V_35 ) ;
}
F_2 ( V_2 -> V_11 , L_4 ) ;
F_2 ( V_2 -> V_11 , L_5 , V_4 ) ;
F_2 ( V_2 -> V_11 , L_6 ,
F_17 ( & V_6 -> V_14 ) ) ;
F_2 ( V_2 -> V_11 , L_7 ,
F_9 ( & V_6 -> V_14 ) ,
F_4 ( & V_6 -> V_14 ) ? L_8 : L_9 ) ;
V_4 -> V_7 = V_7 ;
switch ( V_7 ) {
case V_22 :
V_10 = L_10 ;
break;
case V_23 :
V_10 = L_11 ;
break;
case V_31 :
V_10 = L_12 ;
break;
default:
V_10 = L_13 ;
break;
}
F_2 ( V_2 -> V_11 , L_14 , V_10 ) ;
switch ( V_4 -> V_13 ) {
case V_26 :
type = L_15 ;
break;
case V_25 :
type = L_16 ;
break;
case V_42 :
type = L_17 ;
break;
case V_43 :
type = L_18 ;
break;
default:
type = L_13 ;
break;
}
F_2 ( V_2 -> V_11 , L_19 , type ) ;
if ( V_4 -> V_13 == V_25 ) {
F_2 ( V_2 -> V_11 , L_20 ,
V_4 -> V_30 ) ;
F_2 ( V_2 -> V_11 , L_21 ,
V_4 -> V_35 ) ;
}
}
static struct V_3 * F_18 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_2 V_44 )
{
struct V_3 * V_4 ;
if ( ! V_6 -> V_21 )
return NULL ;
V_4 = F_19 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_2 -> V_45 -> V_46 > 0 &&
F_20 ( V_2 , V_4 , V_44 ) < 0 ) {
F_21 ( V_2 , V_4 ) ;
return NULL ;
}
return V_4 ;
}
void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_47 ;
if ( V_2 -> V_45 -> V_46 > 0 ) {
F_22 ( V_2 , V_4 ) ;
} else if ( V_4 -> V_48 ) {
if ( V_4 -> V_13 == V_26 )
V_47 = 4096 ;
else
V_47 = V_2 -> V_45 -> V_49 ;
F_23 ( V_2 -> V_11 , V_47 , V_4 -> V_48 ,
V_4 -> V_50 ) ;
}
F_24 ( V_4 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_51 ;
int V_52 ;
V_52 = V_2 -> V_45 -> V_53 ;
if ( V_2 -> V_54 + V_2 -> V_55 <
V_52
&& V_2 -> V_54 < V_52 - 1 ) {
V_51 = 0 ;
} else {
F_16 ( V_2 -> V_11 ,
L_22
L_23 , V_12 , V_52 ,
V_2 -> V_54 , V_2 -> V_55 ) ;
V_51 = - V_56 ;
}
return V_51 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_51 ;
T_3 V_57 ;
V_51 = 0 ;
if ( V_4 -> V_7 == V_31 || V_4 -> V_24 ) {
V_57 = 100 - V_4 -> V_30 ;
} else {
V_57 = 900 - V_4 -> V_30 ;
}
if ( V_2 -> V_58 > V_57 ) {
F_27 ( V_2 -> V_11 ,
L_24 ,
V_12 , V_2 -> V_58 , V_4 -> V_30 ) ;
V_51 = - V_56 ;
}
return V_51 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_59 ;
T_1 V_60 ;
int V_51 = 0 ;
V_59 = F_11 ( V_4 -> V_18 ) * F_10 ( V_4 -> V_18 ) ;
V_60 = V_2 -> V_45 -> V_49 ;
if ( V_59 > V_60 ) {
F_27 ( V_2 -> V_11 ,
L_25 ,
V_12 , V_59 , V_60 ) ;
V_51 = - V_56 ;
}
return V_51 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_51 ;
V_51 = F_25 ( V_2 ) ;
if ( V_51 ) {
F_16 ( V_2 -> V_11 ,
L_26 ,
V_12 ) ;
return V_51 ;
}
V_51 = F_26 ( V_2 , V_4 ) ;
if ( V_51 ) {
F_16 ( V_2 -> V_11 ,
L_27 ,
V_12 ) ;
return V_51 ;
}
V_51 = F_28 ( V_2 , V_4 ) ;
if ( V_51 ) {
F_16 ( V_2 -> V_11 ,
L_28 ,
V_12 ) ;
return V_51 ;
}
if ( V_2 -> V_45 -> V_46 > 0 )
F_30 ( & V_4 -> V_20 , & V_2 -> V_61 ) ;
else
F_30 ( & V_4 -> V_20 ,
& V_2 -> V_62 ) ;
V_2 -> V_54 ++ ;
V_2 -> V_58 += V_4 -> V_30 ;
return V_51 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_32 ( & V_4 -> V_20 ) ;
V_2 -> V_54 -- ;
V_2 -> V_58 -= V_4 -> V_30 ;
}
int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_51 = 0 ;
T_1 V_63 ;
if ( F_34 ( V_4 ) )
F_2 ( V_2 -> V_11 , L_1 , V_12 ) ;
if ( ! F_35 ( & V_4 -> V_20 ) )
return V_51 ;
if ( F_36 ( V_4 ) ) {
F_30 ( & V_4 -> V_20 ,
& V_2 -> V_64 ) ;
} else {
V_51 = F_29 ( V_2 , V_4 ) ;
if ( V_51 == 0 ) {
if ( ! V_2 -> V_65 ) {
V_63 = F_15 ( V_2 -> V_36 + V_66 ) ;
V_63 |= V_67 ;
F_37 ( V_63 , V_2 -> V_36 + V_66 ) ;
}
V_2 -> V_65 ++ ;
}
}
return V_51 ;
}
void F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_63 ;
F_2 ( V_2 -> V_11 , L_1 , V_12 ) ;
if ( F_35 ( & V_4 -> V_20 ) )
return;
if ( F_36 ( V_4 ) ) {
if ( V_2 -> V_68 == & V_4 -> V_20 )
V_2 -> V_68 =
V_2 -> V_68 -> V_69 ;
F_32 ( & V_4 -> V_20 ) ;
} else {
F_31 ( V_2 , V_4 ) ;
V_2 -> V_65 -- ;
if ( ! V_2 -> V_65 ) {
V_63 = F_15 ( V_2 -> V_36 + V_66 ) ;
V_63 &= ~ V_67 ;
F_37 ( V_63 , V_2 -> V_36 + V_66 ) ;
}
}
}
static void F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_33 ,
int V_70 )
{
T_4 V_71 ;
if ( V_70 ) {
V_4 -> V_32 = V_33 ;
V_71 = F_14 ( V_4 -> V_41 , 1 ) ;
if ( F_40 ( V_33 , V_71 ) ) {
if ( V_4 -> V_13 != V_26 ||
V_4 -> V_15 != 0 ) {
V_4 -> V_32 =
F_14 ( V_4 -> V_32 , 1 ) ;
}
}
} else {
V_4 -> V_32 = F_14 ( V_4 -> V_41 ,
V_4 -> V_35 ) ;
if ( F_40 ( V_4 -> V_32 , V_33 ) )
V_4 -> V_32 = V_33 ;
V_4 -> V_32 |= 0x7 ;
V_4 -> V_41 = V_4 -> V_32 ;
}
}
void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_70 )
{
if ( F_34 ( V_4 ) )
F_2 ( V_2 -> V_11 , L_1 , V_12 ) ;
if ( F_36 ( V_4 ) ) {
F_38 ( V_2 , V_4 ) ;
if ( ! F_35 ( & V_4 -> V_19 ) )
F_33 ( V_2 , V_4 ) ;
} else {
T_4 V_33 = F_42 ( V_2 ) ;
if ( V_4 -> V_24 ) {
F_39 ( V_2 , V_4 , V_33 ,
V_70 ) ;
} else {
V_4 -> V_32 = F_14 ( V_4 -> V_32 ,
V_4 -> V_35 ) ;
if ( F_40 ( V_4 -> V_32 , V_33 ) )
V_4 -> V_32 = V_33 ;
}
if ( F_35 ( & V_4 -> V_19 ) ) {
F_38 ( V_2 , V_4 ) ;
} else {
if ( V_4 -> V_32 == V_33 )
F_43 ( & V_4 -> V_20 ,
& V_2 -> V_61 ) ;
else
F_43 ( & V_4 -> V_20 ,
& V_2 -> V_62 ) ;
}
}
}
void F_44 ( struct V_72 * V_73 , struct V_5 * V_6 )
{
V_73 -> V_6 = V_6 ;
if ( F_3 ( & V_6 -> V_14 ) ==
V_42 ) {
V_73 -> V_16 = V_74 ;
V_73 -> V_75 = V_76 ;
}
V_73 -> V_77 = 0 ;
V_73 -> V_78 = V_79 ;
V_73 -> V_80 = 0 ;
V_73 -> V_81 = 0 ;
V_6 -> V_73 = V_73 ;
}
int F_45 ( struct V_1 * V_2 , struct V_72 * V_73 ,
struct V_3 * * V_4 , T_2 V_44 )
{
struct V_5 * V_6 = V_73 -> V_6 ;
unsigned long V_82 ;
int V_83 = 0 ;
int V_84 ;
if ( * V_4 == NULL ) {
* V_4 = F_18 ( V_2 , V_6 , V_44 ) ;
if ( * V_4 == NULL )
return - V_85 ;
V_83 = 1 ;
}
F_46 ( & V_2 -> V_86 , V_82 ) ;
V_84 = F_33 ( V_2 , * V_4 ) ;
if ( V_84 )
goto V_87;
V_73 -> V_4 = * V_4 ;
F_30 ( & V_73 -> V_88 , & ( * V_4 ) -> V_19 ) ;
F_47 ( & V_2 -> V_86 , V_82 ) ;
return 0 ;
V_87:
if ( V_83 ) {
struct V_72 * V_89 , * V_90 ;
struct V_3 * V_91 = * V_4 ;
* V_4 = NULL ;
F_38 ( V_2 , V_91 ) ;
F_48 (qtd2, qtd2_tmp, &qh_tmp->qtd_list,
qtd_list_entry)
F_49 ( V_2 , V_89 , V_91 ) ;
F_47 ( & V_2 -> V_86 , V_82 ) ;
F_21 ( V_2 , V_91 ) ;
} else {
F_47 ( & V_2 -> V_86 , V_82 ) ;
}
return V_84 ;
}
