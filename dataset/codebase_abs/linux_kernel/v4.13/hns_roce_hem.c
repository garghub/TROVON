struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = NULL ;
struct V_1 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
void * V_12 ;
F_2 ( V_5 & V_13 ) ;
V_8 = F_3 ( sizeof( * V_8 ) ,
V_5 & ~ ( V_13 | V_14 ) ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_15 = 0 ;
F_4 ( & V_8 -> V_16 ) ;
V_11 = F_5 ( V_17 ) ;
while ( V_4 > 0 ) {
if ( ! V_7 ) {
V_7 = F_3 ( sizeof( * V_7 ) ,
V_5 & ~ ( V_13 | V_14 ) ) ;
if ( ! V_7 )
goto V_18;
F_6 ( V_7 -> V_10 , V_19 ) ;
V_7 -> V_4 = 0 ;
V_7 -> V_20 = 0 ;
F_7 ( & V_7 -> V_21 , & V_8 -> V_16 ) ;
}
while ( 1 << V_11 > V_4 )
-- V_11 ;
V_10 = & V_7 -> V_10 [ V_7 -> V_4 ] ;
V_12 = F_8 ( & V_3 -> V_22 -> V_23 , V_24 << V_11 ,
& F_9 ( V_10 ) , V_5 ) ;
if ( ! V_12 )
goto V_18;
F_10 ( V_10 , V_12 , V_24 << V_11 ) ;
F_2 ( V_10 -> V_25 ) ;
F_11 ( V_10 ) = V_24 << V_11 ;
++ V_7 -> V_4 ;
++ V_7 -> V_20 ;
V_4 -= 1 << V_11 ;
}
return V_8 ;
V_18:
F_12 ( V_3 , V_8 ) ;
return NULL ;
}
void F_12 ( struct V_2 * V_3 , struct V_1 * V_8 )
{
struct V_6 * V_7 , * V_26 ;
int V_27 ;
if ( ! V_8 )
return;
F_13 (chunk, tmp, &hem->chunk_list, list) {
for ( V_27 = 0 ; V_27 < V_7 -> V_4 ; ++ V_27 )
F_14 ( & V_3 -> V_22 -> V_23 ,
V_7 -> V_10 [ V_27 ] . V_28 ,
F_15 ( F_16 ( & V_7 -> V_10 [ V_27 ] ) ) ,
F_9 ( & V_7 -> V_10 [ V_27 ] ) ) ;
F_17 ( V_7 ) ;
}
F_17 ( V_8 ) ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_29 * V_30 , unsigned long V_31 )
{
struct V_32 * V_23 = & V_3 -> V_22 -> V_23 ;
T_2 * V_33 = & V_3 -> V_34 ;
unsigned long V_35 = 0 ;
unsigned long V_36 ;
struct V_37 V_38 ;
void T_3 * V_39 ;
T_4 V_40 = 0 ;
T_4 V_41 [ 2 ] ;
T_4 V_42 = 0 ;
T_5 V_43 = 0 ;
int V_44 = 0 ;
unsigned long V_27 = ( V_31 & ( V_30 -> V_45 - 1 ) ) /
( V_46 / V_30 -> V_47 ) ;
switch ( V_30 -> type ) {
case V_48 :
F_19 ( V_40 , V_49 ,
V_50 , V_48 ) ;
break;
case V_51 :
F_19 ( V_40 , V_49 ,
V_50 ,
V_51 ) ;
break;
case V_52 :
F_19 ( V_40 , V_49 ,
V_50 , V_52 ) ;
break;
case V_53 :
F_19 ( V_40 , V_49 ,
V_50 ,
V_53 ) ;
break;
default:
return V_44 ;
}
F_19 ( V_40 , V_54 ,
V_55 , V_31 ) ;
F_20 ( V_40 , V_56 , 0 ) ;
F_20 ( V_40 , V_57 , 1 ) ;
for ( F_21 ( V_30 -> V_8 [ V_27 ] , & V_38 ) ;
! F_22 ( & V_38 ) ; F_23 ( & V_38 ) ) {
V_43 = F_24 ( & V_38 ) >> V_58 ;
F_25 ( V_33 , V_36 ) ;
V_39 = V_3 -> V_59 + V_60 ;
V_35 = F_26 ( V_61 ) + V_62 ;
while ( 1 ) {
if ( F_27 ( V_39 ) >> V_63 ) {
if ( ! ( F_28 ( V_62 , V_35 ) ) ) {
F_29 ( V_23 , L_1 ) ;
F_30 ( V_33 , V_36 ) ;
return - V_64 ;
}
} else {
break;
}
F_31 ( V_65 ) ;
}
V_42 = ( T_4 ) V_43 ;
F_19 ( V_40 , V_66 ,
V_67 ,
V_43 >> V_68 ) ;
V_41 [ 0 ] = V_42 ;
V_41 [ 1 ] = V_40 ;
F_32 ( V_41 ,
V_3 -> V_59 + V_69 ) ;
F_30 ( V_33 , V_36 ) ;
}
return V_44 ;
}
int F_33 ( struct V_2 * V_3 ,
struct V_29 * V_30 , unsigned long V_31 )
{
struct V_32 * V_23 = & V_3 -> V_22 -> V_23 ;
int V_44 = 0 ;
unsigned long V_27 ;
V_27 = ( V_31 & ( V_30 -> V_45 - 1 ) ) / ( V_46 /
V_30 -> V_47 ) ;
F_34 ( & V_30 -> V_70 ) ;
if ( V_30 -> V_8 [ V_27 ] ) {
++ V_30 -> V_8 [ V_27 ] -> V_15 ;
goto V_71;
}
V_30 -> V_8 [ V_27 ] = F_1 ( V_3 ,
V_46 >> V_72 ,
( V_30 -> V_73 ? V_74 :
V_75 ) | V_14 ) ;
if ( ! V_30 -> V_8 [ V_27 ] ) {
V_44 = - V_76 ;
goto V_71;
}
if ( F_18 ( V_3 , V_30 , V_31 ) ) {
V_44 = - V_77 ;
F_29 ( V_23 , L_2 ) ;
goto V_71;
}
++ V_30 -> V_8 [ V_27 ] -> V_15 ;
V_71:
F_35 ( & V_30 -> V_70 ) ;
return V_44 ;
}
void F_36 ( struct V_2 * V_3 ,
struct V_29 * V_30 , unsigned long V_31 )
{
struct V_32 * V_23 = & V_3 -> V_22 -> V_23 ;
unsigned long V_27 ;
V_27 = ( V_31 & ( V_30 -> V_45 - 1 ) ) /
( V_46 / V_30 -> V_47 ) ;
F_34 ( & V_30 -> V_70 ) ;
if ( -- V_30 -> V_8 [ V_27 ] -> V_15 == 0 ) {
if ( V_3 -> V_78 -> V_79 ( V_3 , V_30 , V_31 ) )
F_37 ( V_23 , L_3 ) ;
F_12 ( V_3 , V_30 -> V_8 [ V_27 ] ) ;
V_30 -> V_8 [ V_27 ] = NULL ;
}
F_35 ( & V_30 -> V_70 ) ;
}
void * F_38 ( struct V_29 * V_30 , unsigned long V_31 ,
T_6 * V_80 )
{
struct V_6 * V_7 ;
unsigned long V_81 ;
int V_27 ;
int V_25 , V_82 ;
struct V_1 * V_8 ;
struct V_83 * V_83 = NULL ;
if ( ! V_30 -> V_73 )
return NULL ;
F_34 ( & V_30 -> V_70 ) ;
V_81 = ( V_31 & ( V_30 -> V_45 - 1 ) ) * V_30 -> V_47 ;
V_8 = V_30 -> V_8 [ V_81 / V_46 ] ;
V_82 = V_25 = V_81 % V_46 ;
if ( ! V_8 )
goto V_71;
F_39 (chunk, &hem->chunk_list, list) {
for ( V_27 = 0 ; V_27 < V_7 -> V_4 ; ++ V_27 ) {
if ( V_80 && V_82 >= 0 ) {
if ( F_11 ( & V_7 -> V_10 [ V_27 ] ) >
( T_4 ) V_82 )
* V_80 = F_9 (
& V_7 -> V_10 [ V_27 ] ) + V_82 ;
V_82 -= F_11 ( & V_7 -> V_10 [ V_27 ] ) ;
}
if ( V_7 -> V_10 [ V_27 ] . V_28 > ( T_4 ) V_25 ) {
V_83 = F_16 ( & V_7 -> V_10 [ V_27 ] ) ;
goto V_71;
}
V_25 -= V_7 -> V_10 [ V_27 ] . V_28 ;
}
}
V_71:
F_35 ( & V_30 -> V_70 ) ;
return V_83 ? F_15 ( V_83 ) + V_25 : NULL ;
}
int F_40 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
unsigned long V_84 , unsigned long V_35 )
{
unsigned long V_85 = V_46 / V_30 -> V_47 ;
unsigned long V_27 = 0 ;
int V_44 = 0 ;
for ( V_27 = V_84 ; V_27 <= V_35 ; V_27 += V_85 ) {
V_44 = F_33 ( V_3 , V_30 , V_27 ) ;
if ( V_44 )
goto V_18;
}
return 0 ;
V_18:
while ( V_27 > V_84 ) {
V_27 -= V_85 ;
F_36 ( V_3 , V_30 , V_27 ) ;
}
return V_44 ;
}
void F_41 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
unsigned long V_84 , unsigned long V_35 )
{
unsigned long V_27 ;
for ( V_27 = V_84 ; V_27 <= V_35 ;
V_27 += V_46 / V_30 -> V_47 )
F_36 ( V_3 , V_30 , V_27 ) ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_29 * V_30 , T_4 type ,
unsigned long V_47 , unsigned long V_86 ,
int V_87 )
{
unsigned long V_88 ;
unsigned long V_89 ;
V_88 = V_46 / V_47 ;
V_89 = ( V_86 + V_88 - 1 ) / V_88 ;
V_30 -> V_8 = F_43 ( V_89 , sizeof( * V_30 -> V_8 ) , V_74 ) ;
if ( ! V_30 -> V_8 )
return - V_76 ;
V_30 -> type = type ;
V_30 -> V_89 = V_89 ;
V_30 -> V_45 = V_86 ;
V_30 -> V_47 = V_47 ;
V_30 -> V_73 = V_87 ;
F_44 ( & V_30 -> V_70 ) ;
return 0 ;
}
void F_45 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
struct V_32 * V_23 = & V_3 -> V_22 -> V_23 ;
unsigned long V_27 ;
for ( V_27 = 0 ; V_27 < V_30 -> V_89 ; ++ V_27 )
if ( V_30 -> V_8 [ V_27 ] ) {
if ( V_3 -> V_78 -> V_79 ( V_3 , V_30 ,
V_27 * V_46 / V_30 -> V_47 ) )
F_29 ( V_23 , L_3 ) ;
F_12 ( V_3 , V_30 -> V_8 [ V_27 ] ) ;
}
F_17 ( V_30 -> V_8 ) ;
}
void F_46 ( struct V_2 * V_3 )
{
F_45 ( V_3 , & V_3 -> V_90 . V_30 ) ;
F_45 ( V_3 , & V_3 -> V_91 . V_92 ) ;
F_45 ( V_3 , & V_3 -> V_91 . V_91 ) ;
F_45 ( V_3 , & V_3 -> V_93 . V_94 ) ;
F_45 ( V_3 , & V_3 -> V_93 . V_95 ) ;
}
