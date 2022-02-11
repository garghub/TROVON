static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_5 = 0 ;
T_1 V_6 = 0 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = F_2 ( & V_2 -> V_8 [ V_6 ] ) ;
if ( ( V_4 [ V_6 ] . V_9 ) && V_5 ) {
V_2 -> V_10 = V_4 [ V_6 ] . V_11 ;
break;
}
}
return V_6 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_12 = false ;
T_1 V_6 = 0 ;
T_2 V_5 = 0 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = F_2 ( & V_2 -> V_8 [ V_6 ] ) ;
if ( V_5 ) {
if ( V_4 [ V_6 ] . V_9 ) {
V_4 [ V_6 ] . V_11 =
( ( V_4 [ V_6 ] . V_11 > V_2 -> V_10 ) ?
V_4 [ V_6 ] . V_11 - V_2 -> V_10 : 0 ) ;
} else {
V_4 [ V_6 ] . V_9 = 1 ;
V_4 [ V_6 ] . V_11 = V_4 [ V_6 ] . V_13 ;
V_12 = true ;
}
} else {
V_4 [ V_6 ] . V_11 = 0 ;
V_4 [ V_6 ] . V_9 = 0 ;
}
}
return V_12 ;
}
static T_2 F_4 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 ;
T_2 V_20 = 0 ;
T_3 V_21 = V_2 -> V_4 [ V_14 ] . V_21 * 32 ;
T_4 V_22 ;
struct V_23 V_24 ;
V_24 . V_25 = V_26 * 5 * 10 ;
if ( V_14 == V_27 )
V_21 = ( ( V_21 << 5 ) / 80 ) ;
if ( F_2 ( & V_2 -> V_8 [ V_14 ] ) )
V_19 = F_5 ( & V_2 -> V_8 [ V_14 ] ) ;
else
return 0 ;
do {
V_22 = F_6 ( V_16 -> V_28 ,
V_16 -> V_29 [ 0 ] ,
V_2 -> V_30 ,
V_19 -> V_31 , & V_24 ) ;
V_21 -= F_7 ( V_22 ) ;
V_20 += 1 ;
if ( F_2 ( & V_2 -> V_8 [ V_14 ] ) - V_20 )
V_19 = V_19 -> V_32 ;
else
break;
} while ( V_21 > 0 );
return V_20 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
bool V_12 = false ;
T_2 V_5 = 0 ;
T_1 V_14 = V_33 ;
T_1 V_6 = 0 ;
if ( F_2 ( & V_2 -> V_8 [ V_34 ] ) ) {
V_14 = V_34 ;
return V_14 ;
}
if ( F_2 ( & V_2 -> V_8 [ V_35 ] ) ) {
if ( ! V_2 -> V_36 )
V_14 = V_35 ;
return V_14 ;
}
if ( V_2 -> V_37 )
return V_14 ;
if ( V_2 -> V_20 != 0 ) {
-- V_2 -> V_20 ;
return V_2 -> V_38 ;
}
V_39:
V_12 = false ;
V_14 = F_1 ( V_2 ) ;
V_6 = V_14 ;
for (; V_6 < V_7 ; V_6 ++ ) {
V_5 = F_2 ( & V_2 -> V_8 [ V_6 ] ) ;
if ( ( ( V_2 -> V_4 [ V_6 ] . V_9 ) &&
( V_2 -> V_4 [ V_6 ] . V_11 < V_2 -> V_10 ) ) &&
V_5 ) {
V_2 -> V_10 = V_2 -> V_4 [ V_6 ] . V_11 ;
V_14 = V_6 ;
}
}
if ( V_14 < V_7 )
V_2 -> V_4 [ V_14 ] . V_9 = 0 ;
V_12 = F_3 ( V_2 ) ;
V_5 = F_2 ( & V_2 -> V_8 [ V_14 ] ) ;
if ( ! V_5 ) {
if ( V_12 )
goto V_39;
V_14 = V_33 ;
return V_14 ;
}
V_2 -> V_38 = V_14 ;
V_5 = F_2 ( & V_2 -> V_8 [ V_14 ] ) ;
if ( V_14 == V_40 || V_14 == V_27 ) {
V_2 -> V_20 = F_4 ( V_2 , V_14 ) ;
V_2 -> V_20 -= 1 ;
}
return V_14 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
T_1 V_14 = V_19 -> V_41 ;
if ( V_14 >= V_42 ) {
F_10 ( V_43 , L_1 ,
V_44 , V_14 ) ;
F_11 ( V_19 ) ;
return;
}
F_12 ( & V_2 -> V_8 [ V_14 ] , V_19 ) ;
}
static struct V_18 * F_13 ( struct V_1 * V_2 ,
T_1 V_14 )
{
if ( V_14 >= V_42 ) {
F_10 ( V_43 , L_1 ,
V_44 , V_14 ) ;
return NULL ;
}
return F_14 ( & V_2 -> V_8 [ V_14 ] ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 ;
unsigned long V_45 , V_46 ;
T_1 V_14 ;
int V_47 ;
V_45 = V_48 ;
while ( 1 ) {
V_14 = F_8 ( V_2 ) ;
F_10 ( V_49 ,
L_2 , V_44 , V_14 ) ;
if ( V_14 == V_33 ) {
F_10 ( V_49 , L_3 , V_44 ) ;
break;
}
F_16 ( & V_2 -> V_50 ) ;
V_47 = V_16 -> V_51 ( V_16 , V_14 ) ;
if ( ( V_47 <= 0 ) ) {
F_17 ( & V_2 -> V_50 ) ;
break;
}
if ( ( V_14 < V_35 ) &&
( ( F_2 ( & V_2 -> V_8 [ V_14 ] ) ) <=
V_52 ) ) {
if ( F_18 ( V_16 -> V_28 , F_19 ( V_14 ) ) )
F_20 ( V_16 -> V_28 ,
F_19 ( V_14 ) ) ;
}
V_19 = F_13 ( V_2 , V_14 ) ;
if ( V_19 == NULL ) {
F_10 ( V_43 , L_4 ) ;
F_17 ( & V_2 -> V_50 ) ;
break;
}
if ( V_14 == V_35 ) {
V_47 = F_21 ( V_2 , V_19 ) ;
} else if ( V_14 == V_34 ) {
V_47 = F_22 ( V_2 , V_19 ) ;
F_11 ( V_19 ) ;
} else {
V_47 = F_23 ( V_2 , V_19 ) ;
}
if ( V_47 ) {
F_17 ( & V_2 -> V_50 ) ;
break;
}
V_2 -> V_53 . V_54 [ V_14 ] ++ ;
V_46 = V_48 ;
F_17 ( & V_2 -> V_50 ) ;
if ( F_24 ( V_46 , V_45 + ( 300 * V_55 ) / 1000 ) )
F_25 () ;
}
}
struct V_56 * F_26 ( struct V_1 * V_2 , T_1 * V_57 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_59 ; V_58 ++ ) {
if ( ! V_2 -> V_60 [ V_58 ] . V_61 )
continue;
if ( ! ( memcmp ( V_2 -> V_60 [ V_58 ] . V_61 -> V_62 ,
V_57 , V_63 ) ) )
return & V_2 -> V_60 [ V_58 ] ;
}
return NULL ;
}
void F_27 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 = V_16 -> V_29 [ 0 ] ;
T_1 V_14 , V_72 = 0 ;
struct V_56 * V_73 = NULL ;
if ( ( ! V_19 ) || ( ! V_19 -> V_31 ) ) {
F_10 ( V_43 , L_5 ,
V_44 ) ;
goto V_74;
}
if ( V_2 -> V_75 != V_76 ) {
F_10 ( V_43 , L_6 , V_44 ) ;
goto V_74;
}
V_65 = F_28 ( V_19 ) ;
V_67 = (struct V_66 * ) V_65 -> V_77 ;
V_69 = (struct V_68 * ) & V_19 -> V_78 [ 0 ] ;
V_67 -> V_79 = 0 ;
if ( ( F_29 ( V_69 -> V_80 ) ) ||
( F_30 ( V_69 -> V_80 ) ) ||
( F_31 ( V_69 -> V_80 ) ) ) {
V_14 = V_35 ;
V_19 -> V_41 = V_14 ;
} else {
if ( F_32 ( V_69 -> V_80 ) ) {
V_72 = ( V_19 -> V_78 [ 24 ] & V_81 ) ;
V_19 -> V_41 = F_33 ( V_72 ) ;
} else {
V_72 = V_82 ;
V_19 -> V_41 = V_83 ;
}
V_14 = V_19 -> V_41 ;
V_67 -> V_72 = V_72 ;
if ( ( V_71 -> type == V_84 ) &&
( ! F_34 ( V_69 -> V_85 ) ) &&
( ! F_35 ( V_69 -> V_85 ) ) ) {
V_73 = F_26 ( V_2 , V_69 -> V_85 ) ;
if ( ! V_73 )
goto V_74;
V_67 -> V_79 = V_73 -> V_79 ;
}
if ( V_73 ) {
if ( ! V_73 -> V_86 [ V_72 ] ) {
V_73 -> V_86 [ V_72 ] = true ;
F_36 ( V_73 -> V_61 ,
V_72 , 0 ) ;
}
}
}
if ( ( V_14 < V_35 ) &&
( ( F_2 ( & V_2 -> V_8 [ V_14 ] ) + 1 ) >=
V_87 ) ) {
F_10 ( V_43 , L_7 , V_44 ) ;
if ( ! F_18 ( V_16 -> V_28 , F_19 ( V_14 ) ) )
F_37 ( V_16 -> V_28 , F_19 ( V_14 ) ) ;
F_38 ( & V_2 -> V_88 . V_89 ) ;
goto V_74;
}
F_9 ( V_2 , V_19 ) ;
F_10 ( V_49 , L_8 , V_44 ) ;
F_38 ( & V_2 -> V_88 . V_89 ) ;
return;
V_74:
F_10 ( V_43 , L_9 , V_44 ) ;
F_39 ( V_2 -> V_17 -> V_28 , V_19 ) ;
}
