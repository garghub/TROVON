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
V_12 = F_5 ( V_2 , V_11 , V_6 + 5 , V_10 ) ;
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
static int F_6 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_15 ;
F_4 ( & V_2 -> V_13 , L_5 , V_4 -> V_9 ) ;
V_15 = F_5 ( V_2 , 0 , ( void * ) V_4 -> V_7 , V_4 -> V_9 ) ;
if ( V_15 < 0 ) {
F_4 ( & V_2 -> V_13 , L_6 , V_15 ) ;
return V_15 ;
}
F_4 ( & V_2 -> V_13 , L_4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const struct V_3 * V_4 , char * V_16 )
{
char * V_17 = V_16 + strlen ( V_16 ) - 4 ;
int V_12 ;
if ( ! strcmp ( V_17 , L_7 ) )
return F_6 ( V_2 , V_4 ) ;
if ( ! strcmp ( V_17 , L_8 ) ) {
V_12 = F_1 ( V_2 , V_4 , 0 ) ;
if ( ! V_12 )
V_12 = F_1 ( V_2 , V_4 , 1 ) ;
return V_12 ;
}
F_3 ( & V_2 -> V_13 , L_9 , V_16 ) ;
return - V_14 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_12 , V_18 = 0 ;
const struct V_3 * V_4 ;
struct V_19 * V_13 = & V_2 -> V_13 ;
char * V_16 ;
if ( ! V_20 . V_21 ) {
F_3 ( V_13 , L_10 ,
V_22 ) ;
return - V_23 ;
}
V_18 = F_9 ( V_2 , & V_20 ) ;
if ( V_18 < 0 ) {
F_10 ( L_11 , V_22 ,
F_11 ( V_13 ) ) ;
return - V_23 ;
}
if ( V_18 >= V_24 ) {
F_10 ( L_12 ,
V_22 , V_18 ) ;
return - V_23 ;
}
V_16 = V_25 [ V_18 ] ;
if ( ! V_16 ) {
F_10 ( L_13 ,
V_22 , F_11 ( V_13 ) ) ;
return - V_26 ;
}
V_12 = F_12 ( & V_4 , V_16 , V_13 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 , L_14 ,
V_16 , V_12 ) ;
return V_12 ;
}
F_7 ( V_2 , V_4 , V_16 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_15 ( void )
{
int V_15 ;
V_15 = F_16 ( & V_20 ) ;
return V_15 ;
}
static void F_17 ( void )
{
F_18 ( & V_20 ) ;
}
