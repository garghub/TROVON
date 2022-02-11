static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
int V_8 , V_9 , V_10 ;
int V_11 = V_12 ;
char * V_13 = V_5 ;
V_7 = F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
V_8 = F_5 ( V_7 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
if ( F_6 ( V_9 , & V_7 -> V_15 ) ) {
V_10 = F_7 ( V_13 , V_11 , L_1 , V_9 + 1 ) ;
V_13 += V_10 ;
V_11 -= V_10 ;
}
}
return V_13 - V_5 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 ;
int V_16 , V_17 ;
V_7 = F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
V_17 = V_18 ;
if ( sscanf ( V_5 , L_2 , & V_16 ) != 1 )
return - V_19 ;
if ( V_16 < 0 ) {
V_16 = - V_16 ;
V_17 = 0 ;
}
if ( V_16 <= 0 || V_16 > F_5 ( V_7 -> V_14 ) )
return - V_20 ;
V_16 -- ;
if ( V_17 )
F_9 ( V_16 , & V_7 -> V_15 ) ;
else
F_10 ( V_16 , & V_7 -> V_15 ) ;
F_11 ( V_7 , V_16 , V_17 ) ;
return V_11 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
int V_10 ;
V_7 = F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
V_10 = F_7 ( V_5 , V_12 , L_1 , V_7 -> V_21 ) ;
return V_10 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 ;
unsigned V_21 ;
unsigned V_22 , V_23 ;
unsigned short V_24 ;
unsigned long V_25 ;
T_1 V_26 ;
V_7 = F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
if ( F_14 ( V_5 , 0 , & V_21 ) < 0 )
return - V_19 ;
if ( V_21 < 100 || V_21 >= 125 ) {
F_15 ( V_7 , L_3
L_4 , V_21 ) ;
return - V_19 ;
}
V_26 = - V_19 ;
F_16 ( & V_7 -> V_27 , V_25 ) ;
if ( V_21 < V_7 -> V_21 ) {
V_24 = 0 ;
for ( V_22 = 0 ; V_22 < V_7 -> V_28 ; ++ V_22 )
for ( V_23 = 0 ; V_23 < 7 ; ++ V_23 )
V_24 = F_17 ( V_24 ,
F_18 ( V_7 , V_22 , V_23 ) ) ;
if ( V_24 > V_21 ) {
F_15 ( V_7 ,
L_5
L_6
L_7 ,
V_24 , V_21 ) ;
goto V_29;
}
}
F_15 ( V_7 , L_8
L_9 ,
100 * V_21 / 125 , V_21 ) ;
if ( V_21 != 100 )
F_19 ( V_7 , L_10 ) ;
V_7 -> V_21 = V_21 ;
V_26 = V_11 ;
V_29:
F_20 ( & V_7 -> V_27 , V_25 ) ;
return V_26 ;
}
static inline int F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_30 = F_22 ( V_7 ) -> V_31 . V_30 ;
int V_32 = 0 ;
if ( ! F_23 ( V_7 ) )
V_32 = F_24 ( V_30 , & V_33 ) ;
if ( V_32 )
goto V_34;
V_32 = F_24 ( V_30 , & V_35 ) ;
V_34:
return V_32 ;
}
static inline void F_25 ( struct V_6 * V_7 )
{
struct V_1 * V_30 = F_22 ( V_7 ) -> V_31 . V_30 ;
if ( ! F_23 ( V_7 ) )
F_26 ( V_30 , & V_33 ) ;
F_26 ( V_30 , & V_35 ) ;
}
