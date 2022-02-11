static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 ;
if ( F_2 ( V_2 -> V_5 , V_3 ) ) {
unsigned long V_6 =
V_2 -> V_5 - V_3 ;
int V_7 = F_3 ( V_6 ) ;
if ( V_7 > 0 ) {
return - V_8 ;
}
}
V_2 -> V_5 += V_9 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 -> V_13 ;
struct V_14 * V_15 = V_11 -> V_15 ;
char * V_16 = V_2 -> V_17 ;
int V_18 = sizeof( V_2 -> V_17 ) ;
int V_19 , V_20 ;
if ( ( V_2 -> V_21 ++ % 32 ) == 0 ) {
V_20 = snprintf ( V_16 , V_18 , L_1 ) ;
V_16 += V_20 ;
V_18 -= V_20 ;
for ( V_19 = 0 ; V_19 < V_15 -> V_22 ; V_19 ++ ) {
const struct V_23 * V_24 = & V_15 -> V_25 [ V_19 ] ;
V_20 = snprintf ( V_16 , V_18 , L_2 , V_24 -> V_26 ) ;
V_16 += V_20 ;
V_18 -= V_20 ;
}
} else {
T_1 V_27 = 0 , V_28 = 0 ;
T_1 V_29 [ 5 ] ;
T_1 V_30 ;
int V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_5 ( V_15 , & V_27 , & V_28 ,
F_6 ( V_29 ) , V_29 ) ;
if ( V_7 < 0 )
return V_7 ;
V_30 = V_28 ? 1000 * V_27 / V_28 : 0 ;
V_20 = snprintf ( V_16 , V_18 , L_3 , V_30 / 10 , V_30 % 10 ) ;
V_16 += V_20 ;
V_18 -= V_20 ;
for ( V_19 = 0 ; V_19 < V_7 ; V_19 ++ ) {
V_30 = V_29 [ V_19 ] / 10000 ;
V_20 = snprintf ( V_16 , V_18 , L_4 ,
V_30 / 100 , V_30 % 100 ) ;
V_16 += V_20 ;
V_18 -= V_20 ;
}
}
V_20 = snprintf ( V_16 , V_18 , L_5 ) ;
V_16 += V_20 ;
V_18 -= V_20 ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = V_16 - V_2 -> V_17 ;
return 0 ;
}
static T_2 F_7 ( struct V_33 * V_33 , char T_3 * V_17 ,
T_4 V_34 , T_5 * V_35 )
{
struct V_1 * V_2 = V_33 -> V_36 ;
int V_20 = 0 , V_7 ;
F_8 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_31 >= V_2 -> V_32 ) {
V_7 = F_4 ( V_2 ) ;
if ( V_7 )
goto V_38;
}
V_20 = F_9 ( ( int ) V_34 , V_2 -> V_32 - V_2 -> V_31 ) ;
V_7 = F_10 ( V_17 , & V_2 -> V_17 [ V_2 -> V_31 ] , V_20 ) ;
if ( V_7 )
goto V_38;
V_2 -> V_31 += V_20 ;
* V_35 += V_20 ;
V_38:
F_11 ( & V_2 -> V_37 ) ;
if ( V_7 )
return V_7 ;
return V_20 ;
}
static int F_12 ( struct V_39 * V_39 , struct V_33 * V_33 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
struct V_41 * V_12 = V_2 -> V_12 ;
struct V_10 * V_11 = V_12 -> V_13 ;
struct V_14 * V_15 = V_11 -> V_15 ;
int V_7 = 0 ;
F_8 ( & V_12 -> V_42 ) ;
if ( V_2 -> V_43 || ! V_15 ) {
V_7 = - V_44 ;
goto V_38;
}
V_33 -> V_36 = V_2 ;
V_2 -> V_43 = true ;
V_2 -> V_21 = 0 ;
V_2 -> V_32 = 0 ;
V_2 -> V_31 = 0 ;
F_13 ( V_15 ) ;
V_2 -> V_5 = V_4 + V_9 ;
V_38:
F_11 ( & V_12 -> V_42 ) ;
return V_7 ;
}
static int F_14 ( struct V_39 * V_39 , struct V_33 * V_33 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
struct V_10 * V_11 = V_2 -> V_12 -> V_13 ;
F_15 ( V_11 -> V_15 ) ;
V_2 -> V_43 = false ;
return 0 ;
}
int F_16 ( struct V_45 * V_46 )
{
struct V_10 * V_11 = V_46 -> V_12 -> V_13 ;
struct V_1 * V_2 ;
if ( V_11 -> V_2 )
return 0 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_12 = V_46 -> V_12 ;
F_18 ( & V_2 -> V_37 ) ;
V_11 -> V_2 = V_2 ;
V_2 -> V_49 = F_17 ( sizeof( * V_2 -> V_49 ) , V_47 ) ;
if ( ! V_2 -> V_49 )
goto V_50;
V_2 -> V_51 = F_19 ( L_6 , V_52 | V_53 ,
V_46 -> V_54 , V_2 , & V_55 ) ;
if ( ! V_2 -> V_51 ) {
F_20 ( L_7 ,
V_46 -> V_54 -> V_56 . V_26 ) ;
goto V_50;
}
V_2 -> V_49 -> V_46 = V_46 ;
V_2 -> V_49 -> V_57 = V_2 -> V_51 ;
V_2 -> V_49 -> V_58 = NULL ;
F_8 ( & V_46 -> V_59 ) ;
F_21 ( & V_2 -> V_49 -> V_60 , & V_46 -> V_61 ) ;
F_11 ( & V_46 -> V_59 ) ;
return 0 ;
V_50:
F_22 ( V_46 ) ;
return - 1 ;
}
void F_22 ( struct V_45 * V_46 )
{
struct V_10 * V_11 = V_46 -> V_12 -> V_13 ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( ! V_2 )
return;
V_11 -> V_2 = NULL ;
F_23 ( V_2 -> V_51 ) ;
if ( V_2 -> V_49 ) {
F_8 ( & V_46 -> V_59 ) ;
F_24 ( & V_2 -> V_49 -> V_60 ) ;
F_11 ( & V_46 -> V_59 ) ;
F_25 ( V_2 -> V_49 ) ;
}
F_26 ( & V_2 -> V_37 ) ;
F_25 ( V_2 ) ;
}
