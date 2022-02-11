static double F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
double V_5 = V_2 -> V_6 ;
int V_7 ;
if ( ! V_4 -> V_8 )
return V_5 ;
for ( V_7 = 1 ; V_7 < V_4 -> V_9 -> V_10 - 1 ; V_7 ++ )
V_5 *= V_2 -> V_11 [ V_7 ] ;
V_5 /= ( V_2 -> V_11 [ V_7 ] + 1 ) ;
return V_5 ;
}
static void F_2 ( struct V_3 * V_4 , struct V_1 * V_12 )
{
F_3 ( & V_4 -> V_13 ) ;
F_4 ( & V_12 -> V_14 ) ;
F_5 ( & V_4 -> V_13 ) ;
}
static void F_6 ( struct V_15 * V_16 , struct V_1 * V_17 )
{
struct V_18 * * V_19 = & V_16 -> V_18 ;
struct V_18 * V_20 = NULL ;
struct V_1 * V_21 ;
while ( * V_19 != NULL ) {
V_20 = * V_19 ;
V_21 = F_7 ( V_20 , struct V_1 , V_18 ) ;
if ( V_17 -> V_5 > V_21 -> V_5 )
V_19 = & ( * V_19 ) -> V_22 ;
else
V_19 = & ( * V_19 ) -> V_23 ;
}
F_8 ( & V_17 -> V_18 , V_20 , V_19 ) ;
F_9 ( & V_17 -> V_18 , V_16 ) ;
}
T_1 F_10 ( struct V_3 * V_4 , char * V_24 , T_1 V_25 )
{
struct V_26 * V_7 ;
float V_27 = V_4 -> V_28 / V_4 -> V_29 ;
float V_30 = V_4 -> V_31 / V_4 -> V_29 ;
float V_32 = ( 100.0 * V_4 -> V_33 ) / V_4 -> V_28 ;
T_1 V_34 = 0 ;
if ( ! V_35 ) {
V_34 = SNPRINTF ( V_24 , V_25 ,
L_1
L_2 , V_27 ,
100.0 - ( 100.0 * ( ( V_27 - V_30 ) /
V_27 ) ) ,
V_32 ) ;
} else {
float V_36 = V_4 -> V_37 / V_4 -> V_29 ;
float V_38 = V_4 -> V_39 / V_4 -> V_29 ;
float V_40 = V_4 -> V_41 / V_4 -> V_29 ;
V_34 = SNPRINTF ( V_24 , V_25 ,
L_3
L_4
L_5 , V_27 ,
100.0 - ( 100.0 * ( ( V_27 - V_30 ) /
V_27 ) ) ,
100.0 - ( 100.0 * ( ( V_27 - V_36 ) /
V_27 ) ) ,
100.0 - ( 100.0 * ( ( V_27 -
V_38 ) /
V_27 ) ) ,
100.0 - ( 100.0 * ( ( V_27 -
V_40 ) /
V_27 ) ) ,
V_32 ) ;
}
if ( V_4 -> V_9 -> V_10 == 1 || ! V_4 -> V_8 ) {
struct V_26 * V_42 ;
V_42 = F_11 ( V_4 -> V_9 -> V_43 . V_44 , struct V_26 , V_14 ) ;
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_6 V_45 L_7 ,
( V_46 ) V_42 -> V_47 . V_48 ,
V_4 -> V_49 ? L_8 : L_9 ) ;
}
if ( ! V_4 -> V_8 ) {
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_10 ,
F_12 ( V_4 -> V_50 ) ) ;
} else {
T_1 V_51 = V_25 - 30 ;
F_13 (counter, &top->evlist->entries, node) {
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_11 ,
V_7 -> V_52 ? L_12 : L_9 ,
F_12 ( V_7 ) ) ;
if ( V_34 > V_51 ) {
sprintf ( V_24 + V_51 - 3 , L_13 ) ;
V_34 = V_51 - 1 ;
break;
}
}
}
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_14 ) ;
if ( V_4 -> V_53 != - 1 )
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_15 ,
V_4 -> V_53 ) ;
else if ( V_4 -> V_54 != - 1 )
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_16 ,
V_4 -> V_54 ) ;
else
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_17 ) ;
if ( V_4 -> V_55 )
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_18 ,
V_4 -> V_9 -> V_56 -> V_57 > 1 ? L_19 : L_9 , V_4 -> V_55 ) ;
else {
if ( V_4 -> V_54 != - 1 )
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_20 ) ;
else
V_34 += SNPRINTF ( V_24 + V_34 , V_25 - V_34 , L_21 ,
V_4 -> V_9 -> V_56 -> V_57 ,
V_4 -> V_9 -> V_56 -> V_57 > 1 ? L_19 : L_9 ) ;
}
return V_34 ;
}
void F_14 ( struct V_3 * V_4 )
{
V_4 -> V_28 = V_4 -> V_37 = V_4 -> V_31 =
V_4 -> V_33 = V_4 -> V_39 =
V_4 -> V_41 = 0 ;
}
float F_15 ( struct V_3 * V_4 , struct V_15 * V_58 )
{
struct V_1 * V_12 , * V_59 ;
float V_60 = 0.0 ;
int V_61 = ! V_4 -> V_8 ? V_4 -> V_50 -> V_52 : 0 , V_62 ;
F_3 ( & V_4 -> V_13 ) ;
V_12 = F_11 ( V_4 -> V_63 . V_44 , struct V_1 , V_14 ) ;
F_5 ( & V_4 -> V_13 ) ;
V_4 -> V_64 = 0 ;
F_16 (syme, n, &top->active_symbols, node) {
V_12 -> V_6 = V_12 -> V_11 [ V_61 ] ;
if ( V_12 -> V_6 != 0 ) {
if ( ( V_4 -> V_65 &&
V_12 -> V_66 -> V_67 -> V_68 == V_69 ) ||
( V_4 -> V_70 &&
V_12 -> V_66 -> V_67 -> V_68 == V_71 ) ) {
F_2 ( V_4 , V_12 ) ;
continue;
}
V_12 -> V_5 = F_1 ( V_12 , V_4 ) ;
if ( ( int ) V_12 -> V_6 >= V_4 -> V_72 ) {
F_6 ( V_58 , V_12 ) ;
++ V_4 -> V_64 ;
}
V_60 += V_12 -> V_6 ;
for ( V_62 = 0 ; V_62 < V_4 -> V_9 -> V_10 ; V_62 ++ )
V_12 -> V_11 [ V_62 ] = V_4 -> V_73 ? 0 : V_12 -> V_11 [ V_62 ] * 7 / 8 ;
} else
F_2 ( V_4 , V_12 ) ;
}
return V_60 ;
}
void F_17 ( struct V_3 * V_4 , struct V_15 * V_58 ,
int * V_74 , int * V_75 , int * V_76 )
{
struct V_18 * V_77 ;
int V_78 = 0 ;
* V_76 = * V_74 = * V_75 = 0 ;
for ( V_77 = F_18 ( V_58 ) ; V_77 ; V_77 = F_19 ( V_77 ) ) {
struct V_1 * V_12 = F_7 ( V_77 , struct V_1 , V_18 ) ;
struct V_79 * V_2 = F_20 ( V_12 ) ;
if ( ++ V_78 > V_4 -> V_80 ||
( int ) V_12 -> V_6 < V_4 -> V_72 )
continue;
if ( V_12 -> V_66 -> V_67 -> V_81 > * V_74 )
* V_74 = V_12 -> V_66 -> V_67 -> V_81 ;
if ( V_12 -> V_66 -> V_67 -> V_82 > * V_75 )
* V_75 = V_12 -> V_66 -> V_67 -> V_82 ;
if ( V_2 -> V_83 > * V_76 )
* V_76 = V_2 -> V_83 ;
}
}
