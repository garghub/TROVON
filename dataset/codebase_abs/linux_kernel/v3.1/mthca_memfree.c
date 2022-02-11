static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 > 0 )
F_2 ( V_2 -> V_7 , V_4 -> V_8 , V_4 -> V_9 ,
V_10 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 )
F_3 ( F_4 ( & V_4 -> V_8 [ V_5 ] ) ,
F_5 ( V_4 -> V_8 [ V_5 ] . V_11 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 ) {
F_7 ( & V_2 -> V_7 -> V_2 , V_4 -> V_8 [ V_5 ] . V_11 ,
F_8 ( F_4 ( & V_4 -> V_8 [ V_5 ] ) ) ,
F_9 ( & V_4 -> V_8 [ V_5 ] ) ) ;
}
}
void F_10 ( struct V_1 * V_2 , struct V_12 * V_13 , int V_14 )
{
struct V_3 * V_4 , * V_15 ;
if ( ! V_13 )
return;
F_11 (chunk, tmp, &icm->chunk_list, list) {
if ( V_14 )
F_6 ( V_2 , V_4 ) ;
else
F_1 ( V_2 , V_4 ) ;
F_12 ( V_4 ) ;
}
F_12 ( V_13 ) ;
}
static int F_13 ( struct V_16 * V_8 , int V_17 , T_1 V_18 )
{
struct V_19 * V_19 ;
V_19 = F_14 ( V_18 | V_20 , V_17 ) ;
if ( ! V_19 )
return - V_21 ;
F_15 ( V_8 , V_19 , V_22 << V_17 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_2 , struct V_16 * V_8 ,
int V_17 , T_1 V_18 )
{
void * V_24 = F_17 ( V_2 , V_22 << V_17 , & F_9 ( V_8 ) ,
V_18 ) ;
if ( ! V_24 )
return - V_21 ;
F_18 ( V_8 , V_24 , V_22 << V_17 ) ;
F_19 ( V_8 -> V_25 ) ;
F_20 ( V_8 ) = V_22 << V_17 ;
return 0 ;
}
struct V_12 * F_21 ( struct V_1 * V_2 , int V_9 ,
T_1 V_18 , int V_14 )
{
struct V_12 * V_13 ;
struct V_3 * V_4 = NULL ;
int V_26 ;
int V_27 ;
F_19 ( V_14 && ( V_18 & V_28 ) ) ;
V_13 = F_22 ( sizeof *V_13 , V_18 & ~ ( V_28 | V_29 ) ) ;
if ( ! V_13 )
return V_13 ;
V_13 -> V_30 = 0 ;
F_23 ( & V_13 -> V_31 ) ;
V_26 = F_5 ( V_32 ) ;
while ( V_9 > 0 ) {
if ( ! V_4 ) {
V_4 = F_22 ( sizeof *V_4 ,
V_18 & ~ ( V_28 | V_29 ) ) ;
if ( ! V_4 )
goto V_33;
F_24 ( V_4 -> V_8 , V_34 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_6 = 0 ;
F_25 ( & V_4 -> V_35 , & V_13 -> V_31 ) ;
}
while ( 1 << V_26 > V_9 )
-- V_26 ;
if ( V_14 )
V_27 = F_16 ( & V_2 -> V_7 -> V_2 ,
& V_4 -> V_8 [ V_4 -> V_9 ] ,
V_26 , V_18 ) ;
else
V_27 = F_13 ( & V_4 -> V_8 [ V_4 -> V_9 ] ,
V_26 , V_18 ) ;
if ( ! V_27 ) {
++ V_4 -> V_9 ;
if ( V_14 )
++ V_4 -> V_6 ;
else if ( V_4 -> V_9 == V_34 ) {
V_4 -> V_6 = F_26 ( V_2 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 ,
V_10 ) ;
if ( V_4 -> V_6 <= 0 )
goto V_33;
}
if ( V_4 -> V_9 == V_34 )
V_4 = NULL ;
V_9 -= 1 << V_26 ;
} else {
-- V_26 ;
if ( V_26 < 0 )
goto V_33;
}
}
if ( ! V_14 && V_4 ) {
V_4 -> V_6 = F_26 ( V_2 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 ,
V_10 ) ;
if ( V_4 -> V_6 <= 0 )
goto V_33;
}
return V_13 ;
V_33:
F_10 ( V_2 , V_13 , V_14 ) ;
return NULL ;
}
int F_27 ( struct V_1 * V_2 , struct V_36 * V_37 , int V_38 )
{
int V_5 = ( V_38 & ( V_37 -> V_39 - 1 ) ) * V_37 -> V_40 / V_41 ;
int V_27 = 0 ;
F_28 ( & V_37 -> V_42 ) ;
if ( V_37 -> V_13 [ V_5 ] ) {
++ V_37 -> V_13 [ V_5 ] -> V_30 ;
goto V_43;
}
V_37 -> V_13 [ V_5 ] = F_21 ( V_2 , V_41 >> V_44 ,
( V_37 -> V_45 ? V_46 : V_47 ) |
V_29 , V_37 -> V_14 ) ;
if ( ! V_37 -> V_13 [ V_5 ] ) {
V_27 = - V_21 ;
goto V_43;
}
if ( F_29 ( V_2 , V_37 -> V_13 [ V_5 ] ,
V_37 -> V_48 + V_5 * V_41 ) ) {
F_10 ( V_2 , V_37 -> V_13 [ V_5 ] , V_37 -> V_14 ) ;
V_37 -> V_13 [ V_5 ] = NULL ;
V_27 = - V_21 ;
goto V_43;
}
++ V_37 -> V_13 [ V_5 ] -> V_30 ;
V_43:
F_30 ( & V_37 -> V_42 ) ;
return V_27 ;
}
void F_31 ( struct V_1 * V_2 , struct V_36 * V_37 , int V_38 )
{
int V_5 ;
if ( ! F_32 ( V_2 ) )
return;
V_5 = ( V_38 & ( V_37 -> V_39 - 1 ) ) * V_37 -> V_40 / V_41 ;
F_28 ( & V_37 -> V_42 ) ;
if ( -- V_37 -> V_13 [ V_5 ] -> V_30 == 0 ) {
F_33 ( V_2 , V_37 -> V_48 + V_5 * V_41 ,
V_41 / V_49 ) ;
F_10 ( V_2 , V_37 -> V_13 [ V_5 ] , V_37 -> V_14 ) ;
V_37 -> V_13 [ V_5 ] = NULL ;
}
F_30 ( & V_37 -> V_42 ) ;
}
void * F_34 ( struct V_36 * V_37 , int V_38 , T_2 * V_50 )
{
int V_51 , V_25 , V_52 , V_5 ;
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_19 * V_19 = NULL ;
if ( ! V_37 -> V_45 )
return NULL ;
F_28 ( & V_37 -> V_42 ) ;
V_51 = ( V_38 & ( V_37 -> V_39 - 1 ) ) * V_37 -> V_40 ;
V_13 = V_37 -> V_13 [ V_51 / V_41 ] ;
V_52 = V_25 = V_51 % V_41 ;
if ( ! V_13 )
goto V_43;
F_35 (chunk, &icm->chunk_list, list) {
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 ) {
if ( V_50 && V_52 >= 0 ) {
if ( F_20 ( & V_4 -> V_8 [ V_5 ] ) > V_52 )
* V_50 = F_9 ( & V_4 -> V_8 [ V_5 ] ) +
V_52 ;
V_52 -= F_20 ( & V_4 -> V_8 [ V_5 ] ) ;
}
if ( V_4 -> V_8 [ V_5 ] . V_11 > V_25 ) {
V_19 = F_4 ( & V_4 -> V_8 [ V_5 ] ) ;
goto V_43;
}
V_25 -= V_4 -> V_8 [ V_5 ] . V_11 ;
}
}
V_43:
F_30 ( & V_37 -> V_42 ) ;
return V_19 ? F_8 ( V_19 ) + V_25 : NULL ;
}
int F_36 ( struct V_1 * V_2 , struct V_36 * V_37 ,
int V_53 , int V_54 )
{
int V_55 = V_41 / V_37 -> V_40 ;
int V_5 , V_56 ;
for ( V_5 = V_53 ; V_5 <= V_54 ; V_5 += V_55 ) {
V_56 = F_27 ( V_2 , V_37 , V_5 ) ;
if ( V_56 )
goto V_33;
}
return 0 ;
V_33:
while ( V_5 > V_53 ) {
V_5 -= V_55 ;
F_31 ( V_2 , V_37 , V_5 ) ;
}
return V_56 ;
}
void F_37 ( struct V_1 * V_2 , struct V_36 * V_37 ,
int V_53 , int V_54 )
{
int V_5 ;
if ( ! F_32 ( V_2 ) )
return;
for ( V_5 = V_53 ; V_5 <= V_54 ; V_5 += V_41 / V_37 -> V_40 )
F_31 ( V_2 , V_37 , V_5 ) ;
}
struct V_36 * F_38 ( struct V_1 * V_2 ,
T_3 V_48 , int V_40 ,
int V_57 , int V_58 ,
int V_59 , int V_60 )
{
struct V_36 * V_37 ;
int V_61 ;
int V_62 ;
unsigned V_63 ;
int V_5 ;
V_61 = V_41 / V_40 ;
V_62 = F_39 ( V_57 , V_61 ) ;
V_37 = F_22 ( sizeof *V_37 + V_62 * sizeof * V_37 -> V_13 , V_46 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_48 = V_48 ;
V_37 -> V_62 = V_62 ;
V_37 -> V_39 = V_57 ;
V_37 -> V_40 = V_40 ;
V_37 -> V_45 = V_59 ;
V_37 -> V_14 = V_60 ;
F_40 ( & V_37 -> V_42 ) ;
for ( V_5 = 0 ; V_5 < V_62 ; ++ V_5 )
V_37 -> V_13 [ V_5 ] = NULL ;
for ( V_5 = 0 ; V_5 * V_41 < V_58 * V_40 ; ++ V_5 ) {
V_63 = V_41 ;
if ( ( V_5 + 1 ) * V_41 > V_57 * V_40 )
V_63 = V_57 * V_40 - V_5 * V_41 ;
V_37 -> V_13 [ V_5 ] = F_21 ( V_2 , V_63 >> V_44 ,
( V_59 ? V_46 : V_47 ) |
V_29 , V_60 ) ;
if ( ! V_37 -> V_13 [ V_5 ] )
goto V_56;
if ( F_29 ( V_2 , V_37 -> V_13 [ V_5 ] ,
V_48 + V_5 * V_41 ) ) {
F_10 ( V_2 , V_37 -> V_13 [ V_5 ] , V_37 -> V_14 ) ;
V_37 -> V_13 [ V_5 ] = NULL ;
goto V_56;
}
++ V_37 -> V_13 [ V_5 ] -> V_30 ;
}
return V_37 ;
V_56:
for ( V_5 = 0 ; V_5 < V_62 ; ++ V_5 )
if ( V_37 -> V_13 [ V_5 ] ) {
F_33 ( V_2 , V_48 + V_5 * V_41 ,
V_41 / V_49 ) ;
F_10 ( V_2 , V_37 -> V_13 [ V_5 ] , V_37 -> V_14 ) ;
}
F_12 ( V_37 ) ;
return NULL ;
}
void F_41 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_37 -> V_62 ; ++ V_5 )
if ( V_37 -> V_13 [ V_5 ] ) {
F_33 ( V_2 ,
V_37 -> V_48 + V_5 * V_41 ,
V_41 / V_49 ) ;
F_10 ( V_2 , V_37 -> V_13 [ V_5 ] , V_37 -> V_14 ) ;
}
F_12 ( V_37 ) ;
}
static T_3 F_42 ( struct V_1 * V_2 , struct V_64 * V_65 , int V_19 )
{
return V_2 -> V_66 . V_67 +
V_65 -> V_68 * V_2 -> V_66 . V_69 +
V_19 * V_49 ;
}
int F_43 ( struct V_1 * V_2 , struct V_64 * V_65 ,
struct V_70 * V_71 , int V_68 , T_3 V_72 )
{
struct V_19 * V_73 [ 1 ] ;
int V_27 = 0 ;
int V_5 ;
if ( ! F_32 ( V_2 ) )
return 0 ;
if ( V_68 < 0 || V_68 > V_2 -> V_66 . V_69 / 8 )
return - V_74 ;
F_28 ( & V_71 -> V_42 ) ;
V_5 = V_68 / V_75 ;
if ( ( V_71 -> V_19 [ V_5 ] . V_30 >= V_75 ) ||
( V_71 -> V_19 [ V_5 ] . V_76 && V_71 -> V_19 [ V_5 ] . V_76 != V_72 ) ||
( V_72 & 4095 ) ) {
V_27 = - V_74 ;
goto V_43;
}
if ( V_71 -> V_19 [ V_5 ] . V_30 ) {
++ V_71 -> V_19 [ V_5 ] . V_30 ;
goto V_43;
}
V_27 = F_44 ( V_77 , V_77 -> V_78 , V_72 & V_79 , 1 , 1 , 0 ,
V_73 , NULL ) ;
if ( V_27 < 0 )
goto V_43;
F_15 ( & V_71 -> V_19 [ V_5 ] . V_8 , V_73 [ 0 ] , V_49 ,
V_72 & ~ V_79 ) ;
V_27 = F_26 ( V_2 -> V_7 , & V_71 -> V_19 [ V_5 ] . V_8 , 1 , V_80 ) ;
if ( V_27 < 0 ) {
F_45 ( V_73 [ 0 ] ) ;
goto V_43;
}
V_27 = F_46 ( V_2 , F_9 ( & V_71 -> V_19 [ V_5 ] . V_8 ) ,
F_42 ( V_2 , V_65 , V_5 ) ) ;
if ( V_27 ) {
F_2 ( V_2 -> V_7 , & V_71 -> V_19 [ V_5 ] . V_8 , 1 , V_80 ) ;
F_45 ( F_4 ( & V_71 -> V_19 [ V_5 ] . V_8 ) ) ;
goto V_43;
}
V_71 -> V_19 [ V_5 ] . V_76 = V_72 ;
V_71 -> V_19 [ V_5 ] . V_30 = 1 ;
V_43:
F_30 ( & V_71 -> V_42 ) ;
return V_27 ;
}
void F_47 ( struct V_1 * V_2 , struct V_64 * V_65 ,
struct V_70 * V_71 , int V_68 )
{
if ( ! F_32 ( V_2 ) )
return;
F_28 ( & V_71 -> V_42 ) ;
-- V_71 -> V_19 [ V_68 / V_75 ] . V_30 ;
F_30 ( & V_71 -> V_42 ) ;
}
struct V_70 * F_48 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
int V_9 ;
int V_5 ;
if ( ! F_32 ( V_2 ) )
return NULL ;
V_9 = V_2 -> V_66 . V_69 / V_49 ;
V_71 = F_22 ( sizeof *V_71 + V_9 * sizeof * V_71 -> V_19 , V_46 ) ;
if ( ! V_71 )
return F_49 ( - V_21 ) ;
F_40 ( & V_71 -> V_42 ) ;
for ( V_5 = 0 ; V_5 < V_9 ; ++ V_5 ) {
V_71 -> V_19 [ V_5 ] . V_30 = 0 ;
V_71 -> V_19 [ V_5 ] . V_76 = 0 ;
F_24 ( & V_71 -> V_19 [ V_5 ] . V_8 , 1 ) ;
}
return V_71 ;
}
void F_50 ( struct V_1 * V_2 , struct V_64 * V_65 ,
struct V_70 * V_71 )
{
int V_5 ;
if ( ! F_32 ( V_2 ) )
return;
for ( V_5 = 0 ; V_5 < V_2 -> V_66 . V_69 / V_49 ; ++ V_5 ) {
if ( V_71 -> V_19 [ V_5 ] . V_76 ) {
F_33 ( V_2 , F_42 ( V_2 , V_65 , V_5 ) , 1 ) ;
F_2 ( V_2 -> V_7 , & V_71 -> V_19 [ V_5 ] . V_8 , 1 , V_80 ) ;
F_45 ( F_4 ( & V_71 -> V_19 [ V_5 ] . V_8 ) ) ;
}
}
F_12 ( V_71 ) ;
}
int F_51 ( struct V_1 * V_2 , enum V_81 type ,
T_4 V_82 , T_5 * * V_83 )
{
int V_84 ;
int V_53 , V_54 , V_85 ;
int V_5 , V_86 ;
struct V_87 * V_19 ;
int V_27 = 0 ;
F_28 ( & V_2 -> V_71 -> V_42 ) ;
switch ( type ) {
case V_88 :
case V_89 :
V_84 = 0 ;
V_53 = 0 ;
V_54 = V_2 -> V_71 -> V_90 ;
V_85 = 1 ;
break;
case V_91 :
case V_92 :
case V_93 :
V_84 = 1 ;
V_53 = V_2 -> V_71 -> V_9 - 1 ;
V_54 = V_2 -> V_71 -> V_94 ;
V_85 = - 1 ;
break;
default:
V_27 = - V_74 ;
goto V_43;
}
for ( V_5 = V_53 ; V_5 != V_54 ; V_5 += V_85 )
if ( V_2 -> V_71 -> V_19 [ V_5 ] . V_95 &&
! F_52 ( V_2 -> V_71 -> V_19 [ V_5 ] . V_96 ,
V_75 ) ) {
V_19 = V_2 -> V_71 -> V_19 + V_5 ;
goto V_97;
}
for ( V_5 = V_53 ; V_5 != V_54 ; V_5 += V_85 )
if ( ! V_2 -> V_71 -> V_19 [ V_5 ] . V_95 ) {
V_19 = V_2 -> V_71 -> V_19 + V_5 ;
goto V_98;
}
if ( V_2 -> V_71 -> V_90 >= V_2 -> V_71 -> V_94 - 1 ) {
V_27 = - V_21 ;
goto V_43;
}
if ( V_84 == 0 )
++ V_2 -> V_71 -> V_90 ;
else
-- V_2 -> V_71 -> V_94 ;
V_19 = V_2 -> V_71 -> V_19 + V_54 ;
V_98:
V_19 -> V_95 = F_17 ( & V_2 -> V_7 -> V_2 , V_49 ,
& V_19 -> V_99 , V_46 ) ;
if ( ! V_19 -> V_95 ) {
V_27 = - V_21 ;
goto V_43;
}
memset ( V_19 -> V_95 , 0 , V_49 ) ;
V_27 = F_46 ( V_2 , V_19 -> V_99 ,
F_42 ( V_2 , & V_2 -> V_100 , V_5 ) ) ;
if ( V_27 ) {
F_7 ( & V_2 -> V_7 -> V_2 , V_49 ,
V_19 -> V_95 , V_19 -> V_99 ) ;
goto V_43;
}
F_53 ( V_19 -> V_96 , V_75 ) ;
V_97:
V_86 = F_54 ( V_19 -> V_96 , V_75 ) ;
F_55 ( V_86 , V_19 -> V_96 ) ;
if ( V_84 == 1 )
V_86 = V_75 - 1 - V_86 ;
V_27 = V_5 * V_75 + V_86 ;
V_19 -> V_95 [ V_86 ] = F_56 ( ( V_82 << 8 ) | ( type << 5 ) ) ;
* V_83 = ( T_5 * ) & V_19 -> V_95 [ V_86 ] ;
V_43:
F_30 ( & V_2 -> V_71 -> V_42 ) ;
return V_27 ;
}
void F_57 ( struct V_1 * V_2 , int type , int V_101 )
{
int V_5 , V_86 ;
struct V_87 * V_19 ;
V_5 = V_101 / V_75 ;
V_86 = V_101 % V_75 ;
V_19 = V_2 -> V_71 -> V_19 + V_5 ;
F_28 ( & V_2 -> V_71 -> V_42 ) ;
V_19 -> V_95 [ V_86 ] = 0 ;
if ( V_5 >= V_2 -> V_71 -> V_94 )
V_86 = V_75 - 1 - V_86 ;
F_58 ( V_86 , V_19 -> V_96 ) ;
if ( F_59 ( V_19 -> V_96 , V_75 ) &&
V_5 >= V_2 -> V_71 -> V_90 - 1 ) {
F_33 ( V_2 , F_42 ( V_2 , & V_2 -> V_100 , V_5 ) , 1 ) ;
F_7 ( & V_2 -> V_7 -> V_2 , V_49 ,
V_19 -> V_95 , V_19 -> V_99 ) ;
V_19 -> V_95 = NULL ;
if ( V_5 == V_2 -> V_71 -> V_90 ) {
-- V_2 -> V_71 -> V_90 ;
}
if ( V_5 == V_2 -> V_71 -> V_94 )
++ V_2 -> V_71 -> V_94 ;
}
F_30 ( & V_2 -> V_71 -> V_42 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! F_32 ( V_2 ) )
return 0 ;
V_2 -> V_71 = F_22 ( sizeof * V_2 -> V_71 , V_46 ) ;
if ( ! V_2 -> V_71 )
return - V_21 ;
F_40 ( & V_2 -> V_71 -> V_42 ) ;
V_2 -> V_71 -> V_9 = V_2 -> V_66 . V_69 / V_49 ;
V_2 -> V_71 -> V_90 = 0 ;
V_2 -> V_71 -> V_94 = V_2 -> V_71 -> V_9 - 1 ;
V_2 -> V_71 -> V_19 = F_22 ( V_2 -> V_71 -> V_9 *
sizeof * V_2 -> V_71 -> V_19 ,
V_46 ) ;
if ( ! V_2 -> V_71 -> V_19 ) {
F_12 ( V_2 -> V_71 ) ;
return - V_21 ;
}
for ( V_5 = 0 ; V_5 < V_2 -> V_71 -> V_9 ; ++ V_5 )
V_2 -> V_71 -> V_19 [ V_5 ] . V_95 = NULL ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! F_32 ( V_2 ) )
return;
for ( V_5 = 0 ; V_5 < V_2 -> V_71 -> V_9 ; ++ V_5 ) {
if ( ! V_2 -> V_71 -> V_19 [ V_5 ] . V_95 )
continue;
if ( ! F_59 ( V_2 -> V_71 -> V_19 [ V_5 ] . V_96 , V_75 ) )
F_62 ( V_2 , L_1 , V_5 ) ;
F_33 ( V_2 , F_42 ( V_2 , & V_2 -> V_100 , V_5 ) , 1 ) ;
F_7 ( & V_2 -> V_7 -> V_2 , V_49 ,
V_2 -> V_71 -> V_19 [ V_5 ] . V_95 ,
V_2 -> V_71 -> V_19 [ V_5 ] . V_99 ) ;
}
F_12 ( V_2 -> V_71 -> V_19 ) ;
F_12 ( V_2 -> V_71 ) ;
}
