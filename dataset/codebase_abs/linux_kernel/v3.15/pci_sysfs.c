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
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_14 ) ;
int V_15 ;
if ( ! F_8 ( V_2 , V_4 ) )
return V_12 ;
F_9 ( V_14 ) ;
V_15 = F_10 ( V_7 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( V_7 ) ;
if ( V_15 )
return V_15 ;
F_12 ( V_7 -> V_16 ) ;
return V_12 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_17 , V_18 = 0 ;
for ( V_17 = 0 ; V_19 [ V_17 ] ; V_17 ++ ) {
V_18 = F_14 ( V_2 , V_19 [ V_17 ] ) ;
if ( V_18 )
goto error;
}
return 0 ;
error:
while ( -- V_17 >= 0 )
F_15 ( V_2 , V_19 [ V_17 ] ) ;
return V_18 ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_17 ;
for ( V_17 = 0 ; V_19 [ V_17 ] ; V_17 ++ )
F_15 ( V_2 , V_19 [ V_17 ] ) ;
}
