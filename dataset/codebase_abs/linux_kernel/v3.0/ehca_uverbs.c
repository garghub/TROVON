struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof *V_7 , V_8 ) ;
if ( ! V_7 ) {
F_3 ( V_3 , L_1 , V_3 ) ;
return F_4 ( - V_9 ) ;
}
return & V_7 -> V_1 ;
}
int F_5 ( struct V_1 * V_10 )
{
F_6 ( F_7 ( V_10 , struct V_6 , V_1 ) ) ;
return 0 ;
}
static void F_8 ( struct V_11 * V_12 )
{
T_1 * V_13 = ( T_1 * ) V_12 -> V_14 ;
if ( ! V_13 ) {
F_9 ( L_2 ,
V_12 -> V_15 , V_12 -> V_16 ) ;
return;
}
( * V_13 ) ++ ;
if ( ! ( * V_13 ) )
F_9 ( L_3 ,
V_12 -> V_15 , V_12 -> V_16 ) ;
F_10 ( L_4 ,
V_12 -> V_15 , V_12 -> V_16 , * V_13 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
T_1 * V_13 = ( T_1 * ) V_12 -> V_14 ;
if ( ! V_13 ) {
F_9 ( L_2 ,
V_12 -> V_15 , V_12 -> V_16 ) ;
return;
}
( * V_13 ) -- ;
F_10 ( L_4 ,
V_12 -> V_15 , V_12 -> V_16 , * V_13 ) ;
}
static int F_12 ( struct V_11 * V_12 , struct V_17 * V_18 ,
T_1 * V_19 )
{
int V_20 ;
T_2 V_21 , V_22 ;
V_21 = V_12 -> V_16 - V_12 -> V_15 ;
if ( V_21 < V_23 ) {
F_9 ( L_5 , V_12 -> V_16 - V_12 -> V_15 ) ;
return - V_24 ;
}
V_22 = V_18 -> V_25 . V_26 ;
V_12 -> V_27 = F_13 ( V_12 -> V_27 ) ;
F_10 ( L_6 , V_21 , V_22 ) ;
V_20 = F_14 ( V_12 , V_12 -> V_15 , V_22 >> V_28 ,
V_12 -> V_27 ) ;
if ( F_15 ( V_20 ) ) {
F_9 ( L_7 , V_20 ) ;
return - V_9 ;
}
V_12 -> V_14 = V_19 ;
( * V_19 ) ++ ;
V_12 -> V_29 = & V_29 ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_30 * V_31 ,
T_1 * V_19 )
{
int V_20 ;
T_2 V_32 , V_33 ;
struct V_34 * V_34 ;
V_12 -> V_35 |= V_36 ;
V_32 = V_12 -> V_15 ;
for ( V_33 = 0 ; V_33 < V_31 -> V_37 ; V_33 += V_38 ) {
T_2 V_39 = ( T_2 ) F_17 ( V_31 , V_33 ) ;
V_34 = F_18 ( V_39 ) ;
V_20 = F_19 ( V_12 , V_32 , V_34 ) ;
if ( F_15 ( V_20 ) ) {
F_9 ( L_8 , V_20 ) ;
return V_20 ;
}
V_32 += V_38 ;
}
V_12 -> V_14 = V_19 ;
( * V_19 ) ++ ;
V_12 -> V_29 = & V_29 ;
return 0 ;
}
static int F_20 ( struct V_11 * V_12 , struct V_40 * V_41 ,
T_1 V_42 )
{
int V_20 ;
switch ( V_42 ) {
case 0 :
F_21 ( V_41 -> V_43 . V_3 , L_9 , V_41 -> V_44 ) ;
V_20 = F_12 ( V_12 , & V_41 -> V_18 , & V_41 -> V_45 ) ;
if ( F_15 ( V_20 ) ) {
F_3 ( V_41 -> V_43 . V_3 ,
L_10 ,
V_20 , V_41 -> V_44 ) ;
return V_20 ;
}
break;
case 1 :
F_21 ( V_41 -> V_43 . V_3 , L_11 , V_41 -> V_44 ) ;
V_20 = F_16 ( V_12 , & V_41 -> V_30 , & V_41 -> V_46 ) ;
if ( F_15 ( V_20 ) ) {
F_3 ( V_41 -> V_43 . V_3 ,
L_12 ,
V_20 , V_41 -> V_44 ) ;
return V_20 ;
}
break;
default:
F_3 ( V_41 -> V_43 . V_3 , L_13 ,
V_42 , V_41 -> V_44 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_22 ( struct V_11 * V_12 , struct V_47 * V_48 ,
T_1 V_42 )
{
int V_20 ;
switch ( V_42 ) {
case 0 :
F_21 ( V_48 -> V_49 . V_3 , L_14 , V_48 -> V_49 . V_50 ) ;
V_20 = F_12 ( V_12 , & V_48 -> V_18 , & V_48 -> V_45 ) ;
if ( F_15 ( V_20 ) ) {
F_3 ( V_48 -> V_49 . V_3 ,
L_15 ,
V_20 , V_48 -> V_49 . V_50 ) ;
return - V_9 ;
}
break;
case 1 :
F_21 ( V_48 -> V_49 . V_3 , L_16 , V_48 -> V_49 . V_50 ) ;
V_20 = F_16 ( V_12 , & V_48 -> V_51 ,
& V_48 -> V_52 ) ;
if ( F_15 ( V_20 ) ) {
F_3 ( V_48 -> V_49 . V_3 ,
L_17 ,
V_20 , V_48 -> V_49 . V_50 ) ;
return V_20 ;
}
break;
case 2 :
F_21 ( V_48 -> V_49 . V_3 , L_18 , V_48 -> V_49 . V_50 ) ;
V_20 = F_16 ( V_12 , & V_48 -> V_53 ,
& V_48 -> V_54 ) ;
if ( F_15 ( V_20 ) ) {
F_3 ( V_48 -> V_49 . V_3 ,
L_19 ,
V_20 , V_48 -> V_49 . V_50 ) ;
return V_20 ;
}
break;
default:
F_3 ( V_48 -> V_49 . V_3 , L_20 ,
V_42 , V_48 -> V_49 . V_50 ) ;
return - V_24 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_10 , struct V_11 * V_12 )
{
T_2 V_55 = V_12 -> V_56 ;
T_1 V_57 = V_55 & 0x1FFFFFF ;
T_1 V_58 = ( V_55 >> 27 ) & 0x1 ;
T_1 V_42 = ( V_55 >> 25 ) & 0x3 ;
T_1 V_20 ;
struct V_40 * V_41 ;
struct V_47 * V_48 ;
struct V_59 * V_60 ;
switch ( V_58 ) {
case 0 :
F_24 ( & V_61 ) ;
V_41 = F_25 ( & V_62 , V_57 ) ;
F_26 ( & V_61 ) ;
if ( ! V_41 )
return - V_24 ;
if ( ! V_41 -> V_43 . V_60 || V_41 -> V_43 . V_60 -> V_10 != V_10 )
return - V_24 ;
V_20 = F_20 ( V_12 , V_41 , V_42 ) ;
if ( F_15 ( V_20 ) ) {
F_3 ( V_41 -> V_43 . V_3 ,
L_21 ,
V_20 , V_41 -> V_44 ) ;
return V_20 ;
}
break;
case 1 :
F_24 ( & V_63 ) ;
V_48 = F_25 ( & V_64 , V_57 ) ;
F_26 ( & V_63 ) ;
if ( ! V_48 )
return - V_24 ;
V_60 = F_27 ( V_48 ) ? V_48 -> V_65 . V_60 : V_48 -> V_49 . V_60 ;
if ( ! V_60 || V_60 -> V_10 != V_10 )
return - V_24 ;
V_20 = F_22 ( V_12 , V_48 , V_42 ) ;
if ( F_15 ( V_20 ) ) {
F_3 ( V_48 -> V_49 . V_3 ,
L_22 ,
V_20 , V_48 -> V_49 . V_50 ) ;
return V_20 ;
}
break;
default:
F_9 ( L_23 , V_58 ) ;
return - V_24 ;
}
return 0 ;
}
