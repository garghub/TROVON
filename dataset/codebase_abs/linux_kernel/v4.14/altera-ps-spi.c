static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( F_2 ( V_5 -> V_7 ) )
return V_8 ;
return V_9 ;
}
static inline void F_3 ( int V_10 )
{
if ( V_10 > 10 )
F_4 ( V_10 , V_10 + 5 ) ;
else
F_5 ( V_10 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_11 * V_12 ,
const char * V_13 , T_1 V_14 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_15 , V_16 , V_17 ;
int V_18 ;
V_5 -> V_19 = V_12 -> V_20 ;
if ( V_12 -> V_20 & V_21 ) {
F_7 ( & V_3 -> V_22 , L_1 ) ;
return - V_23 ;
}
F_8 ( V_5 -> V_24 , 1 ) ;
F_3 ( V_5 -> V_25 -> V_26 ) ;
if ( ! F_2 ( V_5 -> V_7 ) ) {
F_7 ( & V_3 -> V_22 , L_2 ) ;
return - V_27 ;
}
F_8 ( V_5 -> V_24 , 0 ) ;
V_15 = V_5 -> V_25 -> V_28 ;
V_16 = V_5 -> V_25 -> V_29 ;
V_17 = V_16 / V_15 ;
if ( V_16 % V_15 )
V_17 ++ ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
F_4 ( V_15 , V_15 + 10 ) ;
if ( ! F_2 ( V_5 -> V_7 ) ) {
F_3 ( V_5 -> V_25 -> V_30 ) ;
return 0 ;
}
}
F_7 ( & V_3 -> V_22 , L_3 ) ;
return - V_27 ;
}
static void F_9 ( char * V_13 , T_1 V_31 )
{
T_2 * V_32 = ( T_2 * ) V_13 ;
T_1 V_33 = ( V_31 & 0x03 ) ;
const T_2 * V_34 = ( T_2 * ) ( V_13 + V_31 - V_33 ) ;
while ( V_32 < V_34 ) {
* V_32 = F_10 ( * V_32 ) ;
V_32 ++ ;
}
if ( V_33 ) {
V_13 = ( char * ) V_34 ;
while ( V_33 ) {
* V_13 = F_11 ( * V_13 ) ;
V_13 ++ ;
V_33 -- ;
}
}
}
static int F_12 ( struct V_2 * V_3 , const char * V_13 ,
T_1 V_14 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
const char * V_35 = V_13 ;
const char * V_36 = V_35 + V_14 ;
while ( V_35 < V_36 ) {
int V_37 ;
T_1 V_38 = F_13 ( T_1 , V_36 - V_35 , V_39 ) ;
if ( ! ( V_5 -> V_19 & V_40 ) )
F_9 ( ( char * ) V_35 , V_38 ) ;
V_37 = F_14 ( V_5 -> V_41 , V_35 , V_38 ) ;
if ( V_37 ) {
F_7 ( & V_3 -> V_22 , L_4 ,
V_37 ) ;
return V_37 ;
}
V_35 += V_38 ;
}
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
const char V_42 [] = { 0 } ;
int V_37 ;
if ( F_2 ( V_5 -> V_7 ) ) {
F_7 ( & V_3 -> V_22 , L_5 ) ;
return - V_27 ;
}
if ( ! F_16 ( V_5 -> V_43 ) ) {
if ( ! F_17 ( V_5 -> V_43 ) ) {
F_7 ( & V_3 -> V_22 , L_6 ) ;
return - V_27 ;
}
}
V_37 = F_14 ( V_5 -> V_41 , V_42 , 1 ) ;
if ( V_37 ) {
F_7 ( & V_3 -> V_22 , L_7 , V_37 ) ;
return V_37 ;
}
return 0 ;
}
static int F_18 ( struct V_44 * V_41 )
{
struct V_4 * V_5 ;
const struct V_45 * V_46 ;
V_5 = F_19 ( & V_41 -> V_22 , sizeof( * V_5 ) , V_47 ) ;
if ( ! V_5 )
return - V_48 ;
V_46 = F_20 ( V_49 , & V_41 -> V_22 ) ;
if ( ! V_46 )
return - V_50 ;
V_5 -> V_25 = V_46 -> V_25 ;
V_5 -> V_41 = V_41 ;
V_5 -> V_24 = F_21 ( & V_41 -> V_22 , L_8 , V_51 ) ;
if ( F_16 ( V_5 -> V_24 ) ) {
F_7 ( & V_41 -> V_22 , L_9 ,
F_22 ( V_5 -> V_24 ) ) ;
return F_22 ( V_5 -> V_24 ) ;
}
V_5 -> V_7 = F_21 ( & V_41 -> V_22 , L_10 , V_52 ) ;
if ( F_16 ( V_5 -> V_7 ) ) {
F_7 ( & V_41 -> V_22 , L_11 ,
F_22 ( V_5 -> V_7 ) ) ;
return F_22 ( V_5 -> V_7 ) ;
}
V_5 -> V_43 = F_21 ( & V_41 -> V_22 , L_12 , V_52 ) ;
if ( F_16 ( V_5 -> V_43 ) ) {
F_23 ( & V_41 -> V_22 , L_13 ,
F_22 ( V_5 -> V_43 ) ) ;
}
snprintf ( V_5 -> V_53 , sizeof( V_5 -> V_53 ) , L_14 ,
F_24 ( & V_41 -> V_22 ) , F_25 ( & V_41 -> V_22 ) ) ;
return F_26 ( & V_41 -> V_22 , V_5 -> V_53 ,
& V_54 , V_5 ) ;
}
static int F_27 ( struct V_44 * V_41 )
{
F_28 ( & V_41 -> V_22 ) ;
return 0 ;
}
