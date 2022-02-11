int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
if ( ( V_3 & V_4 ) &&
( V_3 & V_5 ) )
return - V_6 ;
V_2 -> V_7 -> V_8 . V_9 = ( V_3 & V_4 ) != 0 ;
V_2 -> V_7 -> V_8 . V_10 = ( V_3 & V_5 ) != 0 ;
V_2 -> V_7 -> V_8 . V_11 = ( V_3 & V_12 ) != 0 ;
V_2 -> V_7 -> V_8 . V_13 = ( V_3 & V_14 ) != 0 ;
V_2 -> V_7 -> V_8 . V_15 = ( V_3 & V_16 ) != 0 ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 , unsigned long V_3 )
{
if ( ( ( V_3 & V_4 ) &&
( V_3 & V_5 ) ) ||
( ( V_3 & V_4 ) &&
V_2 -> V_7 -> V_8 . V_10 ) ||
( ( V_3 & V_5 ) &&
V_2 -> V_7 -> V_8 . V_9 ) )
return - V_6 ;
V_2 -> V_7 -> V_8 . V_9 |= ( V_3 & V_4 ) != 0 ;
V_2 -> V_7 -> V_8 . V_10 |= ( V_3 & V_5 ) != 0 ;
V_2 -> V_7 -> V_8 . V_11 |= ( V_3 & V_12 ) != 0 ;
V_2 -> V_7 -> V_8 . V_13 |= ( V_3 & V_14 ) != 0 ;
V_2 -> V_7 -> V_8 . V_15 |= ( V_3 & V_16 ) != 0 ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_7 -> V_8 . V_9 &= ( V_3 & V_4 ) == 0 ;
V_2 -> V_7 -> V_8 . V_10 &= ( V_3 & V_5 ) == 0 ;
V_2 -> V_7 -> V_8 . V_11 &= ( V_3 & V_12 ) == 0 ;
V_2 -> V_7 -> V_8 . V_13 &= ( V_3 & V_14 ) == 0 ;
V_2 -> V_7 -> V_8 . V_15 &= ( V_3 & V_16 ) == 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_7 -> V_3 . V_11 ;
}
int F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_7 -> V_3 . V_15 ;
}
int F_6 ( struct V_1 * V_2 , unsigned long V_17 )
{
struct V_18 * V_19 ;
int V_20 ;
if ( ! V_2 || ! V_2 -> V_21 . V_22 )
return - V_23 ;
V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
if ( ! V_19 -> V_24 . V_25 . V_26 )
return - V_6 ;
if ( V_2 -> V_7 -> V_27 == V_28 )
return - V_23 ;
if ( V_2 -> V_7 -> V_27 != V_29 &&
V_2 -> V_7 -> V_27 != V_30 )
return - V_6 ;
V_20 = F_8 ( V_19 ) ;
if ( V_20 == 0 )
V_2 -> V_7 -> V_17 = V_17 ;
return V_20 ;
}
int F_9 ( struct V_1 * V_2 , struct V_31 * V_32 ,
unsigned long V_17 , T_1 V_33 , T_1 V_34 ,
unsigned long V_3 )
{
struct V_18 * V_19 ;
int V_20 ;
if ( ! V_2 || ! V_2 -> V_21 . V_22 )
return - V_23 ;
V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
if ( ! V_19 -> V_24 . V_25 . V_26 )
return - V_6 ;
if ( V_2 -> V_7 -> V_27 == V_28 )
return - V_23 ;
if ( V_2 -> V_7 -> V_27 == V_35 ) {
if ( ! V_2 -> V_7 -> V_3 . V_36 ) {
V_2 -> V_7 -> V_3 . V_36 = V_37 ;
V_2 -> V_7 -> V_17 = V_17 ;
return 0 ;
} else
return - V_38 ;
}
if ( V_2 -> V_7 -> V_27 != V_29 ||
( ( V_19 -> V_24 . V_39 . V_40 . V_41 & V_42 ) &&
! ( V_19 -> V_24 . V_39 . V_40 . V_41 & V_43 ) ) ||
V_2 -> V_7 -> V_3 . V_44 )
return - V_38 ;
V_20 = F_10 ( V_19 , V_3 ) ;
if ( V_20 )
return V_20 ;
if ( V_33 ) {
V_33 &= V_19 -> V_33 ;
if ( V_33 == 0 )
return - V_45 ;
}
V_20 = F_11 ( V_19 , V_32 , V_33 , V_34 ) ;
switch ( V_20 ) {
case 0 :
V_2 -> V_7 -> V_17 = V_17 ;
break;
case - V_45 :
case - V_23 :
F_12 ( V_2 , V_46 ) ;
break;
}
return V_20 ;
}
int F_13 ( struct V_1 * V_2 , struct V_31 * V_32 ,
unsigned long V_17 , T_1 V_33 , T_1 V_34 ,
unsigned long V_3 , int V_47 )
{
int V_20 ;
if ( ! V_2 )
return - V_23 ;
F_14 ( V_2 , V_47 ) ;
V_20 = F_9 ( V_2 , V_32 , V_17 , V_33 , V_34 , V_3 ) ;
if ( V_20 != 0 )
F_14 ( V_2 , 0 ) ;
return V_20 ;
}
int F_15 ( struct V_1 * V_2 , struct V_31 * V_32 ,
unsigned long V_17 , T_1 V_33 , unsigned long V_3 )
{
return F_9 ( V_2 , V_32 , V_17 , V_33 ,
V_48 , V_3 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_31 * V_32 ,
unsigned long V_17 , T_1 V_33 ,
unsigned long V_3 , int V_47 )
{
return F_13 ( V_2 , V_32 , V_17 , V_33 ,
V_48 , V_3 ,
V_47 ) ;
}
int F_17 ( struct V_1 * V_2 , unsigned long V_17 )
{
struct V_18 * V_19 ;
int V_20 ;
if ( ! V_2 || ! V_2 -> V_21 . V_22 )
return - V_23 ;
V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
if ( ! V_19 -> V_24 . V_25 . V_26 )
return - V_6 ;
if ( V_2 -> V_7 -> V_27 == V_28 )
return - V_23 ;
if ( V_2 -> V_7 -> V_27 != V_29 &&
V_2 -> V_7 -> V_27 != V_30 )
return - V_6 ;
V_20 = F_18 ( V_19 ) ;
if ( V_20 == 0 )
V_2 -> V_7 -> V_17 = V_17 ;
return V_20 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
if ( ! V_2 || ! V_2 -> V_21 . V_22 )
return - V_23 ;
V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
if ( ! V_19 -> V_24 . V_25 . V_26 )
return - V_6 ;
if ( V_2 -> V_7 -> V_27 == V_28 )
return - V_23 ;
if ( V_2 -> V_7 -> V_27 != V_29 ||
! ( V_19 -> V_24 . V_39 . V_40 . V_49 & V_50 ) )
return - V_6 ;
return F_20 ( V_19 ) ;
}
int
F_21 ( struct V_1 * V_2 )
{
unsigned int V_41 ;
int V_51 ;
V_41 = F_22 ( & V_2 -> V_7 -> V_52 . V_39 ) ;
V_51 = ( V_41 & V_43 ) ||
( V_41 == ( V_53 | V_54 ) ) ||
( V_41 == V_54 ) ;
if ( ! V_51 &&
! V_2 -> V_7 -> V_8 . V_10 &&
! ( V_41 & V_55 ) &&
! ( V_2 -> V_7 -> V_8 . V_9 &&
( V_41 & V_42 ) ) )
return 0 ;
if ( V_51 )
F_14 ( V_2 , 0 ) ;
if ( V_2 -> V_56 )
V_2 -> V_56 ( V_2 , V_2 -> V_7 -> V_17 ,
& V_2 -> V_7 -> V_52 ) ;
memset ( & V_2 -> V_7 -> V_52 , 0 , sizeof( struct V_52 ) ) ;
return 1 ;
}
struct V_57 * F_23 ( struct V_1 * V_2 , T_2 V_58 )
{
int V_59 ;
if ( V_2 -> V_7 -> V_3 . V_60 == 0 )
return NULL ;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ )
if ( V_2 -> V_7 -> V_62 . V_57 [ V_59 ] . V_58 == V_58 )
return V_2 -> V_7 -> V_62 . V_57 + V_59 ;
return NULL ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
if ( ! V_2 -> V_21 . V_22 )
return 0 ;
V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
return V_19 -> V_33 ;
}
void F_25 ( struct V_1 * V_2 , void * V_63 , int V_64 )
{
struct V_65 * V_66 = V_63 ;
V_66 -> V_64 = V_64 ;
F_26 ( & V_66 -> V_67 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
struct V_65 V_63 ;
T_3 * V_68 ;
int V_64 ;
if ( V_2 -> V_69 ) {
if ( ! V_2 -> V_7 -> V_8 . V_13 )
return - V_6 ;
}
V_68 = F_28 ( 64 , V_70 | V_71 ) ;
if ( ! V_68 )
return - V_72 ;
F_29 ( & V_63 . V_67 ) ;
V_63 . V_64 = - V_73 ;
F_30 ( V_19 -> V_74 ) ;
V_64 = F_31 ( V_19 , ( V_75 ) ( V_76 ) V_19 ) ;
if ( V_64 )
goto V_77;
V_2 -> V_7 -> V_27 = V_78 ,
F_32 ( V_2 , & V_63 , & V_68 [ 0 ] , & V_68 [ 32 ] ) ;
F_33 ( V_19 -> V_74 ) ;
if ( F_34 ( & V_63 . V_67 ) ) {
F_30 ( V_19 -> V_74 ) ;
F_35 ( V_2 ) ;
F_33 ( V_19 -> V_74 ) ;
F_36 ( & V_63 . V_67 ) ;
}
V_64 = V_63 . V_64 ;
F_30 ( V_19 -> V_74 ) ;
F_37 ( V_19 ) ;
V_2 -> V_7 -> V_27 = V_79 ;
V_77:
F_33 ( V_19 -> V_74 ) ;
F_38 ( V_68 ) ;
return V_64 ;
}
void * F_39 ( struct V_1 * V_2 , int V_80 )
{
struct V_18 * V_19 ;
struct V_81 V_82 ;
V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
F_40 ( & V_82 ) ;
V_82 . V_83 = V_19 -> V_24 . V_25 . V_82 [ V_80 ] ;
return F_41 ( V_82 ) ;
}
void F_42 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
* V_85 = V_2 -> V_7 -> V_85 ;
}
int F_43 ( struct V_1 * V_2 , struct V_86 * V_86 ,
unsigned long V_17 , T_3 V_33 , T_3 V_34 )
{
struct V_18 * V_19 ;
int V_64 ;
V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
if ( ! V_19 -> V_24 . V_25 . V_26 )
return - V_6 ;
if ( V_2 -> V_7 -> V_27 == V_35 ) {
if ( ! V_2 -> V_7 -> V_3 . V_36 ) {
V_2 -> V_7 -> V_3 . V_36 = V_87 ;
V_2 -> V_7 -> V_17 = V_17 ;
return 0 ;
} else
return - V_38 ;
}
if ( V_2 -> V_7 -> V_27 != V_29 )
return - V_73 ;
if ( V_33 ) {
V_33 &= V_19 -> V_33 ;
if ( V_33 == 0 )
return - V_45 ;
}
V_64 = F_44 ( V_19 , V_86 , V_33 , V_34 ) ;
if ( V_64 == 0 )
V_2 -> V_7 -> V_17 = V_17 ;
return V_64 ;
}
int F_45 ( struct V_1 * V_2 , struct V_86 * V_86 ,
unsigned long V_17 , T_3 V_33 , T_3 V_34 ,
int V_47 )
{
int V_20 ;
F_14 ( V_2 , V_47 ) ;
V_20 = F_43 ( V_2 , V_86 , V_17 , V_33 , V_34 ) ;
if ( V_20 != 0 )
F_14 ( V_2 , 0 ) ;
return V_20 ;
}
int F_46 ( struct V_1 * V_2 , struct V_86 * V_86 ,
unsigned long V_17 , T_3 V_33 )
{
return F_43 ( V_2 , V_86 , V_17 , V_33 ,
V_48 ) ;
}
int F_47 ( struct V_1 * V_2 , struct V_86 * V_86 ,
unsigned long V_17 , T_3 V_33 , int V_47 )
{
return F_45 ( V_2 , V_86 , V_17 , V_33 ,
V_48 , V_47 ) ;
}
int F_48 ( struct V_1 * V_2 , T_3 V_88 )
{
struct V_18 * V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
struct V_89 V_90 ;
struct V_81 V_82 ;
int V_91 = 0 , V_20 , V_92 ;
if ( V_88 )
V_88 &= V_19 -> V_33 ;
else
V_88 = V_19 -> V_33 ;
F_40 ( & V_82 ) ;
for ( V_92 = 0 ; V_92 < 8 ; V_92 ++ ) {
if ( ! ( V_88 & ( 0x80 >> V_92 ) ) )
continue;
V_82 . V_83 = V_19 -> V_24 . V_25 . V_82 [ V_92 ] ;
V_20 = F_49 ( V_82 , & V_90 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_90 . V_93 )
return 0 ;
if ( ! V_90 . V_94 )
V_91 = 1 ;
V_91 = V_91 ? F_50 ( V_91 , ( int ) V_90 . V_91 ) : V_90 . V_91 ;
}
return V_91 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_2 -> V_21 . V_22 ) ;
if ( ! V_19 -> V_24 . V_25 . V_26 )
return - V_6 ;
if ( V_2 -> V_7 -> V_27 != V_29 )
return - V_73 ;
if ( ! F_52 ( & V_19 -> V_24 . V_39 ) ||
! ( F_53 ( & V_19 -> V_24 . V_39 ) & V_95 ) )
return - V_6 ;
return F_54 ( V_19 ) ;
}
int
F_55 ( struct V_1 * V_2 )
{
return V_2 -> V_7 -> V_96 . V_97 ;
}
