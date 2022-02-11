static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( & V_2 -> V_4 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
V_2 -> V_5 = V_6 ;
}
static int F_4 ( struct V_7 * V_8 )
{
int V_9 ;
T_1 V_10 ;
V_9 = F_5 ( V_8 ) ;
if ( V_9 ) {
F_6 ( L_1 , V_9 ) ;
return V_9 ;
}
V_10 = F_7 ( V_11 ) ;
F_8 ( ! ( V_10 & V_12 ) ,
L_2 ,
V_10 ) ;
return V_9 ;
}
void F_9 ( struct V_7 * V_8 )
{
if ( ! F_10 ( V_8 ) ) {
if ( V_13 . V_14 > 0 ||
V_13 . V_15 > 0 )
F_11 ( L_3 ) ;
V_13 . V_14 = 0 ;
V_13 . V_15 = 0 ;
return;
}
if ( V_13 . V_14 < 0 )
V_13 . V_14 = F_12 ( V_8 ) ;
if ( V_13 . V_14 ) {
if ( F_13 ( V_8 ) )
F_14 ( & V_8 -> V_16 ) ;
if ( F_15 ( & V_8 -> V_17 ) )
V_13 . V_14 = 0 ;
}
if ( ! V_13 . V_14 )
V_13 . V_15 = 0 ;
if ( V_13 . V_15 < 0 )
V_13 . V_15 = F_16 ( V_8 ) ;
}
void F_17 ( struct V_7 * V_8 )
{
struct V_18 * V_17 = & V_8 -> V_17 ;
F_18 ( & V_17 -> V_19 ) ;
V_17 -> V_20 = V_21 ;
}
static void F_19 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_8 -> V_24 . V_23 ;
struct V_3 * V_4 ;
const struct V_25 * V_26 = NULL ;
struct V_27 * V_28 ;
T_2 V_29 ;
int V_30 ;
if ( ! V_2 -> V_31 )
return;
V_2 -> V_5 = V_32 ;
F_20 ( L_4 ,
F_21 ( V_2 -> V_5 ) ) ;
V_30 = F_22 ( & V_26 , V_2 -> V_31 , & V_23 -> V_33 ) ;
if ( V_30 )
goto V_34;
if ( ! V_26 )
goto V_34;
F_20 ( L_5 ,
V_2 -> V_31 , V_26 ) ;
if ( V_26 -> V_29 < sizeof( struct V_27 ) ) {
F_23 ( L_6 ) ;
goto V_34;
}
V_28 = (struct V_27 * ) V_26 -> V_35 ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = ( V_28 -> V_38 - V_28 -> V_39 -
V_28 -> V_40 - V_28 -> V_41 ) * sizeof( T_1 ) ;
if ( V_2 -> V_37 != sizeof( struct V_27 ) ) {
F_23 ( L_7 ) ;
goto V_34;
}
V_2 -> V_42 = V_2 -> V_36 + V_2 -> V_37 ;
V_2 -> V_43 = ( V_28 -> V_44 - V_28 -> V_38 ) * sizeof( T_1 ) ;
if ( V_28 -> V_40 != V_45 ) {
F_23 ( L_8 ) ;
goto V_34;
}
V_2 -> V_46 = V_2 -> V_42 + V_2 -> V_43 ;
V_2 -> V_47 = V_28 -> V_40 * sizeof( T_1 ) ;
V_29 = V_2 -> V_37 + V_2 -> V_43 + V_2 -> V_47 ;
if ( V_26 -> V_29 < V_29 ) {
F_23 ( L_9 ) ;
goto V_34;
}
switch ( V_2 -> type ) {
case V_48 :
V_29 = V_2 -> V_37 + V_2 -> V_43 ;
if ( V_29 > F_24 ( V_8 ) ) {
F_6 ( L_10 ) ;
goto V_34;
}
V_2 -> V_49 = V_28 -> V_17 . V_50 >> 16 ;
V_2 -> V_51 = V_28 -> V_17 . V_50 & 0xFFFF ;
break;
case V_52 :
V_2 -> V_49 = V_28 -> V_16 . V_50 >> 16 ;
V_2 -> V_51 = V_28 -> V_16 . V_50 & 0xFFFF ;
break;
default:
F_6 ( L_11 , V_2 -> type ) ;
V_30 = - V_53 ;
goto V_34;
}
if ( V_2 -> V_54 == 0 && V_2 -> V_55 == 0 ) {
F_23 ( L_12 ,
F_25 ( V_2 -> type ) ) ;
} else if ( V_2 -> V_49 != V_2 -> V_54 ||
V_2 -> V_51 < V_2 -> V_55 ) {
F_23 ( L_13 ,
F_25 ( V_2 -> type ) ,
V_2 -> V_49 , V_2 -> V_51 ,
V_2 -> V_54 , V_2 -> V_55 ) ;
V_30 = - V_53 ;
goto V_34;
}
F_20 ( L_14 ,
V_2 -> V_49 , V_2 -> V_51 ,
V_2 -> V_54 , V_2 -> V_55 ) ;
V_4 = F_26 ( V_8 , V_26 -> V_35 , V_26 -> V_29 ) ;
if ( F_27 ( V_4 ) ) {
V_30 = F_28 ( V_4 ) ;
goto V_34;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_29 = V_26 -> V_29 ;
F_20 ( L_15 ,
V_2 -> V_4 ) ;
F_29 ( V_26 ) ;
V_2 -> V_5 = V_56 ;
return;
V_34:
F_30 ( L_16 ,
V_2 -> V_31 , V_30 ) ;
F_20 ( L_17 ,
V_30 , V_26 , V_2 -> V_4 ) ;
F_29 ( V_26 ) ;
V_2 -> V_5 = V_57 ;
}
void F_31 ( struct V_7 * V_8 )
{
F_19 ( V_8 , & V_8 -> V_16 . V_26 ) ;
F_19 ( V_8 , & V_8 -> V_17 . V_26 ) ;
}
void F_32 ( struct V_7 * V_8 )
{
F_1 ( & V_8 -> V_17 . V_26 ) ;
F_1 ( & V_8 -> V_16 . V_26 ) ;
}
int F_33 ( struct V_7 * V_8 )
{
int V_9 , V_58 ;
if ( ! V_13 . V_14 )
return 0 ;
F_34 ( V_8 ) ;
F_35 ( V_8 ) ;
if ( V_13 . V_15 ) {
V_9 = F_36 ( V_8 ) ;
if ( V_9 )
goto V_59;
}
if ( F_37 ( V_8 ) )
V_58 = 3 ;
else
V_58 = 1 ;
while ( V_58 -- ) {
V_9 = F_4 ( V_8 ) ;
if ( V_9 )
goto V_60;
F_38 ( & V_8 -> V_16 ) ;
V_9 = F_39 ( & V_8 -> V_17 ) ;
if ( V_9 == 0 || V_9 != - V_61 )
break;
F_20 ( L_18
L_19 , V_9 , V_58 ) ;
}
if ( V_9 )
goto V_60;
F_40 ( V_8 ) ;
if ( V_13 . V_15 ) {
if ( V_13 . V_62 >= 0 )
F_41 ( V_8 ) ;
V_9 = F_42 ( V_8 ) ;
if ( V_9 )
goto V_63;
}
return 0 ;
V_63:
F_43 ( V_8 ) ;
V_60:
if ( V_13 . V_15 )
F_44 ( V_8 ) ;
V_59:
F_45 ( V_8 ) ;
F_6 ( L_20 ) ;
if ( V_13 . V_14 > 1 || V_13 . V_15 > 1 )
V_9 = - V_64 ;
else
V_9 = 0 ;
if ( V_13 . V_15 ) {
V_13 . V_15 = 0 ;
F_23 ( L_21 ) ;
}
return V_9 ;
}
void F_46 ( struct V_7 * V_8 )
{
if ( ! V_13 . V_14 )
return;
if ( V_13 . V_15 ) {
F_47 ( V_8 ) ;
F_43 ( V_8 ) ;
F_44 ( V_8 ) ;
}
F_45 ( V_8 ) ;
}
static bool F_48 ( struct V_18 * V_17 , T_1 * V_65 )
{
struct V_7 * V_8 = F_49 ( V_17 ) ;
T_1 V_66 = F_7 ( F_50 ( 0 ) ) ;
* V_65 = V_66 ;
return F_51 ( V_66 ) ;
}
int V_21 ( struct V_18 * V_17 , const T_1 * V_67 , T_1 V_68 )
{
struct V_7 * V_8 = F_49 ( V_17 ) ;
T_1 V_65 ;
int V_69 ;
int V_9 ;
if ( F_52 ( V_68 < 1 || V_68 > 15 ) )
return - V_70 ;
F_53 ( & V_17 -> V_19 ) ;
F_54 ( V_8 , V_71 ) ;
V_8 -> V_17 . V_72 += 1 ;
V_8 -> V_17 . V_73 = V_67 [ 0 ] ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ )
F_55 ( F_50 ( V_69 ) , V_67 [ V_69 ] ) ;
F_56 ( F_50 ( V_69 - 1 ) ) ;
F_55 ( V_74 , V_75 ) ;
V_9 = F_57 ( F_48 ( V_17 , & V_65 ) , 10 ) ;
if ( V_9 )
V_9 = F_58 ( F_48 ( V_17 , & V_65 ) , 10 ) ;
if ( V_65 != V_76 ) {
if ( V_9 != - V_77 )
V_9 = - V_64 ;
F_30 ( L_22
L_23 ,
V_67 [ 0 ] , V_9 , V_65 , F_7 ( F_50 ( 15 ) ) ) ;
V_8 -> V_17 . V_78 += 1 ;
V_8 -> V_17 . V_79 = V_9 ;
}
V_8 -> V_17 . V_80 = V_65 ;
F_59 ( V_8 , V_71 ) ;
F_60 ( & V_17 -> V_19 ) ;
return V_9 ;
}
int F_61 ( struct V_18 * V_17 )
{
struct V_7 * V_8 = F_49 ( V_17 ) ;
T_1 V_67 [ 2 ] ;
V_67 [ 0 ] = V_81 ;
if ( ! F_62 () || F_63 ( V_8 ) )
V_67 [ 1 ] = 0 ;
else
V_67 [ 1 ] = V_82 | V_83 ;
return F_64 ( V_17 , V_67 , F_65 ( V_67 ) ) ;
}
