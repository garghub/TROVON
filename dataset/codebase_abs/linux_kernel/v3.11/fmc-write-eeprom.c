static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_5 )
{
const T_1 * V_6 = V_4 -> V_7 ;
int V_8 = V_4 -> V_9 ;
T_2 V_10 , V_11 ;
int V_12 ;
while ( V_8 > 5 ) {
V_11 = F_2 ( V_6 + 1 ) ;
V_10 = F_2 ( V_6 + 3 ) ;
if ( V_6 [ 0 ] != 'w' || V_10 + 5 > V_8 ) {
F_3 ( & V_2 -> V_13 , L_1 ,
V_6 - V_4 -> V_7 ) ;
return - V_14 ;
}
V_12 = 0 ;
if ( V_5 ) {
F_4 ( & V_2 -> V_13 , L_2 ,
V_10 , V_11 ) ;
V_12 = V_2 -> V_15 -> V_16 ( V_2 , V_11 , V_6 + 5 , V_10 ) ;
}
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 , L_3 ,
V_11 ) ;
return V_12 ;
}
V_6 += 5 + V_10 ;
V_8 -= 5 + V_10 ;
}
if ( V_5 )
F_4 ( & V_2 -> V_13 , L_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_17 ;
F_4 ( & V_2 -> V_13 , L_5 , V_4 -> V_9 ) ;
V_17 = V_2 -> V_15 -> V_16 ( V_2 , 0 , ( void * ) V_4 -> V_7 , V_4 -> V_9 ) ;
if ( V_17 < 0 ) {
F_4 ( & V_2 -> V_13 , L_6 , V_17 ) ;
return V_17 ;
}
F_4 ( & V_2 -> V_13 , L_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , const struct V_3 * V_4 , char * V_18 )
{
char * V_19 = V_18 + strlen ( V_18 ) - 4 ;
int V_12 ;
if ( ! strcmp ( V_19 , L_7 ) )
return F_5 ( V_2 , V_4 ) ;
if ( ! strcmp ( V_19 , L_8 ) ) {
V_12 = F_1 ( V_2 , V_4 , 0 ) ;
if ( ! V_12 )
V_12 = F_1 ( V_2 , V_4 , 1 ) ;
return V_12 ;
}
F_3 ( & V_2 -> V_13 , L_9 , V_18 ) ;
return - V_14 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_12 , V_20 = 0 ;
const struct V_3 * V_4 ;
struct V_21 * V_13 = & V_2 -> V_13 ;
char * V_18 ;
if ( ! V_22 . V_23 ) {
F_3 ( V_13 , L_10 ,
V_24 ) ;
return - V_25 ;
}
if ( V_2 -> V_15 -> V_26 )
V_20 = V_2 -> V_15 -> V_26 ( V_2 , & V_22 ) ;
if ( V_20 < 0 ) {
F_8 ( L_11 , V_24 ,
F_9 ( V_13 ) ) ;
return - V_25 ;
}
if ( V_20 >= V_27 ) {
F_8 ( L_12 ,
V_24 , V_20 ) ;
return - V_25 ;
}
V_18 = V_28 [ V_20 ] ;
if ( ! V_18 ) {
F_8 ( L_13 ,
V_24 , F_9 ( V_13 ) ) ;
return - V_29 ;
}
V_12 = F_10 ( & V_4 , V_18 , V_13 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 , L_14 ,
V_18 , V_12 ) ;
return V_12 ;
}
F_6 ( V_2 , V_4 , V_18 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_13 ( void )
{
int V_17 ;
V_17 = F_14 ( & V_22 ) ;
return V_17 ;
}
static void F_15 ( void )
{
F_16 ( & V_22 ) ;
}
