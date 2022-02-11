static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_10 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return sprintf ( V_5 , L_3 , V_7 -> V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_13 ) ;
int V_14 ;
F_8 ( V_13 ) ;
V_14 = F_9 ( V_7 ) ;
if ( V_14 )
return;
V_14 = F_10 ( V_7 ) ;
if ( V_14 )
return;
F_11 ( V_7 -> V_15 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
int V_17 = F_13 ( V_2 , F_7 ) ;
return V_17 ? V_17 : V_16 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_18 , V_17 = 0 ;
for ( V_18 = 0 ; V_19 [ V_18 ] ; V_18 ++ ) {
V_17 = F_15 ( V_2 , V_19 [ V_18 ] ) ;
if ( V_17 )
goto error;
}
return 0 ;
error:
while ( -- V_18 >= 0 )
F_16 ( V_2 , V_19 [ V_18 ] ) ;
return V_17 ;
}
void F_17 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_19 [ V_18 ] ; V_18 ++ )
F_16 ( V_2 , V_19 [ V_18 ] ) ;
}
