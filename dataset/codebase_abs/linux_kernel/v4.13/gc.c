static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 [ V_8 ] . V_6 ;
F_2 ( V_4 != - 1 ) ;
F_3 ( L_1 ,
V_6 -> V_9 , V_6 -> V_10 + V_6 -> V_11 , V_4 ,
V_2 -> V_12 - V_6 -> V_10 - V_6 -> V_11 ) ;
V_3 = F_4 ( V_6 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_5 ( V_2 , V_4 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_6 ( V_2 , V_8 , V_4 , 0 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_4 = - 1 ;
V_3 = F_7 ( V_6 , V_4 , 0 ) ;
return V_3 ;
}
static int F_8 ( void * V_13 , struct V_14 * V_15 , struct V_14 * V_16 )
{
T_1 V_17 , V_18 ;
struct V_1 * V_2 = V_13 ;
struct V_19 * V_20 , * V_21 ;
F_9 () ;
if ( V_15 == V_16 )
return 0 ;
V_20 = F_10 ( V_15 , struct V_19 , V_22 ) ;
V_21 = F_10 ( V_16 , struct V_19 , V_22 ) ;
F_2 ( F_11 ( V_2 , & V_20 -> V_23 ) == V_24 ) ;
F_2 ( F_11 ( V_2 , & V_21 -> V_23 ) == V_24 ) ;
F_2 ( V_20 -> type == V_25 ) ;
F_2 ( V_21 -> type == V_25 ) ;
V_17 = F_12 ( V_2 , & V_20 -> V_23 ) ;
V_18 = F_12 ( V_2 , & V_21 -> V_23 ) ;
if ( V_17 == V_18 ) {
unsigned int V_26 = F_13 ( V_2 , & V_20 -> V_23 ) ;
unsigned int V_27 = F_13 ( V_2 , & V_21 -> V_23 ) ;
if ( V_26 <= V_27 )
return - 1 ;
} else if ( V_17 <= V_18 )
return - 1 ;
return 1 ;
}
static int F_14 ( void * V_13 , struct V_14 * V_15 ,
struct V_14 * V_16 )
{
T_1 V_17 , V_18 ;
struct V_1 * V_2 = V_13 ;
struct V_19 * V_20 , * V_21 ;
F_9 () ;
if ( V_15 == V_16 )
return 0 ;
V_20 = F_10 ( V_15 , struct V_19 , V_22 ) ;
V_21 = F_10 ( V_16 , struct V_19 , V_22 ) ;
F_2 ( F_11 ( V_2 , & V_20 -> V_23 ) != V_24 &&
F_11 ( V_2 , & V_21 -> V_23 ) != V_24 ) ;
F_2 ( V_20 -> type != V_25 &&
V_21 -> type != V_25 ) ;
if ( V_20 -> type == V_28 ) {
if ( V_21 -> type == V_28 )
return V_21 -> V_29 - V_20 -> V_29 ;
return - 1 ;
}
if ( V_21 -> type == V_28 )
return 1 ;
F_2 ( F_11 ( V_2 , & V_20 -> V_23 ) == V_30 ||
F_11 ( V_2 , & V_20 -> V_23 ) == V_31 ) ;
F_2 ( F_11 ( V_2 , & V_21 -> V_23 ) == V_30 ||
F_11 ( V_2 , & V_21 -> V_23 ) == V_31 ) ;
F_2 ( V_20 -> type == V_32 ||
V_20 -> type == V_33 ) ;
F_2 ( V_21 -> type == V_32 ||
V_21 -> type == V_33 ) ;
V_17 = F_12 ( V_2 , & V_20 -> V_23 ) ;
V_18 = F_12 ( V_2 , & V_21 -> V_23 ) ;
if ( V_17 == V_18 ) {
T_2 V_34 = F_15 ( V_2 , & V_20 -> V_23 ) ;
T_2 V_35 = F_15 ( V_2 , & V_21 -> V_23 ) ;
if ( V_34 <= V_35 )
return - 1 ;
} else if ( V_17 <= V_18 )
return - 1 ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_14 * V_38 , int * V_39 )
{
int V_3 ;
struct V_19 * V_40 , * V_41 ;
* V_39 = V_42 ;
F_17 (snod, tmp, &sleb->nodes, list) {
F_2 ( V_40 -> type == V_28 ||
V_40 -> type == V_25 ||
V_40 -> type == V_32 ||
V_40 -> type == V_33 ||
V_40 -> type == V_43 ) ;
if ( V_40 -> type != V_28 &&
V_40 -> type != V_25 &&
V_40 -> type != V_32 &&
V_40 -> type != V_33 ) {
F_18 ( & V_40 -> V_22 ) ;
F_19 ( V_40 ) ;
continue;
}
F_2 ( F_11 ( V_2 , & V_40 -> V_23 ) == V_24 ||
F_11 ( V_2 , & V_40 -> V_23 ) == V_44 ||
F_11 ( V_2 , & V_40 -> V_23 ) == V_30 ||
F_11 ( V_2 , & V_40 -> V_23 ) == V_31 ) ;
V_3 = F_20 ( V_2 , & V_40 -> V_23 , 0 , V_37 -> V_9 ,
V_40 -> V_10 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! V_3 ) {
F_18 ( & V_40 -> V_22 ) ;
F_19 ( V_40 ) ;
continue;
}
if ( V_40 -> V_29 < * V_39 )
* V_39 = V_40 -> V_29 ;
if ( F_11 ( V_2 , & V_40 -> V_23 ) != V_24 )
F_21 ( & V_40 -> V_22 , V_38 ) ;
}
F_22 ( V_2 , & V_37 -> V_45 , & F_8 ) ;
F_22 ( V_2 , V_38 , & F_14 ) ;
V_3 = F_23 ( V_2 , & V_37 -> V_45 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_24 ( V_2 , V_38 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_19 * V_40 , struct V_5 * V_6 )
{
int V_3 , V_46 = V_6 -> V_9 , V_47 = V_6 -> V_10 + V_6 -> V_11 ;
F_9 () ;
V_3 = F_26 ( V_6 , V_40 -> V_48 , V_40 -> V_29 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_27 ( V_2 , & V_40 -> V_23 , V_37 -> V_9 ,
V_40 -> V_10 , V_46 , V_47 ,
V_40 -> V_29 ) ;
F_18 ( & V_40 -> V_22 ) ;
F_19 ( V_40 ) ;
return V_3 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
int V_3 , V_39 ;
F_29 ( V_38 ) ;
struct V_5 * V_6 = & V_2 -> V_7 [ V_8 ] . V_6 ;
if ( V_6 -> V_9 == - 1 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_16 ( V_2 , V_37 , & V_38 , & V_39 ) ;
if ( V_3 )
goto V_49;
while ( 1 ) {
int V_50 ;
struct V_19 * V_40 , * V_41 ;
F_17 (snod, tmp, &sleb->nodes, list) {
V_50 = V_2 -> V_12 - V_6 -> V_10 - V_6 -> V_11 ;
if ( V_40 -> V_29 > V_50 )
break;
V_3 = F_25 ( V_2 , V_37 , V_40 , V_6 ) ;
if ( V_3 )
goto V_49;
}
F_17 (snod, tmp, &nondata, list) {
V_50 = V_2 -> V_12 - V_6 -> V_10 - V_6 -> V_11 ;
if ( V_50 < V_39 )
break;
if ( V_40 -> V_29 > V_50 ) {
if ( F_11 ( V_2 , & V_40 -> V_23 ) == V_30 ||
V_40 -> V_29 == V_51 )
break;
continue;
}
V_3 = F_25 ( V_2 , V_37 , V_40 , V_6 ) ;
if ( V_3 )
goto V_49;
}
if ( F_30 ( & V_37 -> V_45 ) && F_30 ( & V_38 ) )
break;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_49;
}
return 0 ;
V_49:
F_31 ( & V_38 , & V_37 -> V_45 ) ;
return V_3 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_3 , V_52 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
if ( V_52 == V_8 )
continue;
V_3 = F_33 ( & V_2 -> V_7 [ V_52 ] . V_6 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
int F_34 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_36 * V_37 ;
struct V_19 * V_40 ;
struct V_5 * V_6 = & V_2 -> V_7 [ V_8 ] . V_6 ;
int V_3 = 0 , V_9 = V_55 -> V_9 ;
F_2 ( V_2 -> V_4 != - 1 || V_6 -> V_10 + V_6 -> V_11 == 0 ||
V_2 -> V_56 ) ;
F_2 ( V_2 -> V_4 != V_9 ) ;
F_2 ( V_6 -> V_9 != V_9 ) ;
if ( V_55 -> free + V_55 -> V_57 == V_2 -> V_12 ) {
F_3 ( L_2 , V_55 -> V_9 ) ;
F_2 ( ! ( V_55 -> V_58 & V_59 ) ) ;
if ( V_55 -> free != V_2 -> V_12 ) {
V_3 = F_32 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_35 ( V_2 , V_55 -> V_9 , V_2 -> V_12 ,
0 , 0 , 0 , 0 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_5 ( V_2 , V_55 -> V_9 ) ;
if ( V_3 )
return V_3 ;
if ( V_2 -> V_4 == - 1 ) {
V_2 -> V_4 = V_9 ;
return V_60 ;
}
return V_61 ;
}
V_37 = F_36 ( V_2 , V_9 , 0 , V_2 -> V_62 , 0 ) ;
if ( F_37 ( V_37 ) )
return F_38 ( V_37 ) ;
F_2 ( ! F_30 ( & V_37 -> V_45 ) ) ;
V_40 = F_10 ( V_37 -> V_45 . V_63 , struct V_19 , V_22 ) ;
if ( V_40 -> type == V_64 ) {
struct V_65 * V_66 ;
F_3 ( L_3 ,
V_9 , V_55 -> free , V_55 -> V_57 ) ;
F_39 (snod, &sleb->nodes, list) {
struct V_67 * V_68 = V_40 -> V_48 ;
int V_69 = F_40 ( V_68 -> V_69 ) ;
F_2 ( V_40 -> type == V_64 ) ;
F_41 ( V_2 , F_42 ( V_2 , V_68 ) , & V_40 -> V_23 ) ;
V_3 = F_43 ( V_2 , & V_40 -> V_23 , V_69 , V_9 ,
V_40 -> V_10 ) ;
if ( V_3 )
goto V_49;
}
V_66 = F_44 ( sizeof( struct V_65 ) , V_70 ) ;
if ( ! V_66 ) {
V_3 = - V_71 ;
goto V_49;
}
V_66 -> V_9 = V_9 ;
V_66 -> V_72 = 0 ;
F_45 ( & V_66 -> V_22 , & V_2 -> V_66 ) ;
V_3 = F_35 ( V_2 , V_9 , V_2 -> V_12 , 0 , 0 ,
V_59 , 1 ) ;
if ( V_3 )
goto V_49;
V_3 = V_73 ;
} else {
F_3 ( L_4 ,
V_9 , V_55 -> free , V_55 -> V_57 ) ;
V_3 = F_28 ( V_2 , V_37 ) ;
if ( V_3 )
goto V_74;
V_3 = F_32 ( V_2 ) ;
if ( V_3 )
goto V_74;
V_3 = F_35 ( V_2 , V_9 , V_2 -> V_12 , 0 , 0 , 0 , 0 ) ;
if ( V_3 )
goto V_74;
V_2 -> V_75 = V_9 ;
F_46 () ;
V_2 -> V_76 += 1 ;
F_46 () ;
if ( V_2 -> V_4 == - 1 ) {
V_2 -> V_4 = V_9 ;
V_3 = V_60 ;
} else {
V_3 = F_4 ( V_6 ) ;
if ( V_3 )
goto V_49;
V_3 = F_5 ( V_2 , V_9 ) ;
if ( V_3 )
goto V_49;
V_3 = V_61 ;
}
}
V_49:
F_47 ( V_37 ) ;
return V_3 ;
V_74:
V_2 -> V_75 = V_9 ;
F_46 () ;
V_2 -> V_76 += 1 ;
F_46 () ;
goto V_49;
}
int F_48 ( struct V_1 * V_2 , int V_77 )
{
int V_52 , V_3 , V_78 , V_79 = V_2 -> V_80 ;
struct V_54 V_55 ;
struct V_5 * V_6 = & V_2 -> V_7 [ V_8 ] . V_6 ;
F_49 ( V_2 ) ;
F_2 ( ! V_2 -> V_81 && ! V_2 -> V_82 ) ;
if ( F_50 ( V_2 ) )
return - V_83 ;
F_51 ( & V_6 -> V_84 , V_6 -> V_85 ) ;
if ( V_2 -> V_86 ) {
V_78 = - V_87 ;
goto V_88;
}
F_2 ( ! V_6 -> V_11 ) ;
for ( V_52 = 0 ; ; V_52 ++ ) {
int V_89 , V_90 ;
F_9 () ;
if ( F_50 ( V_2 ) ) {
V_78 = - V_83 ;
break;
}
if ( V_52 > V_91 && ! F_30 ( & V_2 -> V_66 ) ) {
F_3 ( L_5 ) ;
F_52 ( V_2 ) ;
V_78 = - V_83 ;
break;
}
if ( V_52 > V_92 ) {
F_3 ( L_6 ) ;
V_78 = - V_93 ;
break;
}
V_78 = F_53 ( V_2 , & V_55 , V_79 , V_77 ? 0 : 1 ) ;
if ( V_78 ) {
if ( V_78 == - V_93 )
F_3 ( L_7 ) ;
break;
}
F_3 ( L_8 ,
V_55 . V_9 , V_55 . free , V_55 . V_57 , V_55 . free + V_55 . V_57 ,
V_79 ) ;
V_89 = V_2 -> V_12 - V_6 -> V_10 - V_6 -> V_11 ;
if ( V_6 -> V_9 == - 1 )
V_89 = 0 ;
V_78 = F_34 ( V_2 , & V_55 ) ;
if ( V_78 < 0 ) {
if ( V_78 == - V_83 ) {
V_3 = F_54 ( V_2 , V_55 . V_9 ) ;
if ( V_3 )
V_78 = V_3 ;
break;
}
goto V_49;
}
if ( V_78 == V_61 ) {
F_3 ( L_9 , V_55 . V_9 ) ;
V_78 = V_55 . V_9 ;
break;
}
if ( V_78 == V_73 ) {
F_3 ( L_10 , V_55 . V_9 ) ;
continue;
}
F_2 ( V_78 == V_60 ) ;
V_90 = V_2 -> V_12 - V_6 -> V_10 - V_6 -> V_11 ;
F_3 ( L_11 , V_55 . V_9 ,
V_90 - V_89 ) ;
if ( V_90 > V_89 ) {
V_79 >>= 1 ;
if ( V_79 < V_2 -> V_80 )
V_79 = V_2 -> V_80 ;
continue;
}
F_3 ( L_12 ) ;
if ( V_52 < V_91 ) {
F_3 ( L_13 ) ;
continue;
}
V_79 <<= 1 ;
if ( V_79 > V_2 -> V_94 )
V_79 = V_2 -> V_94 ;
F_3 ( L_14 , V_79 ) ;
}
if ( V_78 == - V_93 && ! F_30 ( & V_2 -> V_66 ) ) {
F_3 ( L_15 ) ;
F_52 ( V_2 ) ;
V_78 = - V_83 ;
}
V_3 = F_4 ( V_6 ) ;
if ( ! V_3 )
V_3 = F_5 ( V_2 , V_2 -> V_4 ) ;
if ( V_3 ) {
V_78 = V_3 ;
goto V_49;
}
V_88:
F_55 ( & V_6 -> V_84 ) ;
return V_78 ;
V_49:
F_2 ( V_78 < 0 ) ;
F_2 ( V_78 != - V_93 && V_78 != - V_83 ) ;
F_4 ( V_6 ) ;
F_56 ( V_2 , V_78 ) ;
F_55 ( & V_6 -> V_84 ) ;
F_54 ( V_2 , V_55 . V_9 ) ;
return V_78 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
const struct V_54 * V_55 ;
int V_3 = 0 , V_58 ;
F_58 ( V_2 ) ;
while ( 1 ) {
V_55 = F_59 ( V_2 ) ;
if ( ! V_55 )
break;
F_2 ( ! ( V_55 -> V_58 & V_95 ) ) ;
F_2 ( ! ( V_55 -> V_58 & V_59 ) ) ;
V_3 = F_5 ( V_2 , V_55 -> V_9 ) ;
if ( V_3 )
goto V_49;
V_55 = F_60 ( V_2 , V_55 , V_2 -> V_12 , 0 , V_55 -> V_58 , 0 ) ;
if ( F_37 ( V_55 ) ) {
V_3 = F_38 ( V_55 ) ;
goto V_49;
}
F_2 ( ! ( V_55 -> V_58 & V_95 ) ) ;
F_2 ( ! ( V_55 -> V_58 & V_59 ) ) ;
}
F_39 (idx_gc, &c->idx_gc, list)
V_66 -> V_72 = 1 ;
while ( 1 ) {
V_55 = F_61 ( V_2 ) ;
if ( F_37 ( V_55 ) ) {
V_3 = F_38 ( V_55 ) ;
goto V_49;
}
if ( ! V_55 )
break;
V_66 = F_44 ( sizeof( struct V_65 ) , V_70 ) ;
if ( ! V_66 ) {
V_3 = - V_71 ;
goto V_49;
}
F_2 ( ! ( V_55 -> V_58 & V_95 ) ) ;
F_2 ( V_55 -> V_58 & V_59 ) ;
V_58 = ( V_55 -> V_58 | V_95 ) ^ V_59 ;
V_55 = F_60 ( V_2 , V_55 , V_2 -> V_12 , 0 , V_58 , 1 ) ;
if ( F_37 ( V_55 ) ) {
V_3 = F_38 ( V_55 ) ;
F_19 ( V_66 ) ;
goto V_49;
}
F_2 ( V_55 -> V_58 & V_95 ) ;
F_2 ( ! ( V_55 -> V_58 & V_59 ) ) ;
V_66 -> V_9 = V_55 -> V_9 ;
V_66 -> V_72 = 1 ;
F_45 ( & V_66 -> V_22 , & V_2 -> V_66 ) ;
}
V_49:
F_62 ( V_2 ) ;
return V_3 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_65 * V_66 , * V_41 ;
struct V_5 * V_6 ;
int V_3 = 0 ;
V_6 = & V_2 -> V_7 [ V_8 ] . V_6 ;
F_51 ( & V_6 -> V_84 , V_6 -> V_85 ) ;
F_17 (idx_gc, tmp, &c->idx_gc, list)
if ( V_66 -> V_72 ) {
F_3 ( L_16 , V_66 -> V_9 ) ;
V_3 = F_5 ( V_2 , V_66 -> V_9 ) ;
if ( V_3 )
goto V_49;
V_3 = F_35 ( V_2 , V_66 -> V_9 , V_96 ,
V_96 , 0 , V_95 , - 1 ) ;
if ( V_3 )
goto V_49;
F_18 ( & V_66 -> V_22 ) ;
F_19 ( V_66 ) ;
}
V_49:
F_55 ( & V_6 -> V_84 ) ;
return V_3 ;
}
void F_64 ( struct V_1 * V_2 )
{
while ( ! F_30 ( & V_2 -> V_66 ) ) {
struct V_65 * V_66 ;
V_66 = F_10 ( V_2 -> V_66 . V_63 , struct V_65 ,
V_22 ) ;
V_2 -> V_97 -= 1 ;
F_18 ( & V_66 -> V_22 ) ;
F_19 ( V_66 ) ;
}
}
int F_65 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
int V_9 ;
if ( F_30 ( & V_2 -> V_66 ) )
return - V_93 ;
V_66 = F_10 ( V_2 -> V_66 . V_63 , struct V_65 , V_22 ) ;
V_9 = V_66 -> V_9 ;
F_18 ( & V_66 -> V_22 ) ;
F_19 ( V_66 ) ;
return V_9 ;
}
