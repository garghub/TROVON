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
int F_7 ( struct V_1 * V_2 )
{
int V_12 , V_13 = 0 ;
for ( V_12 = 0 ; V_14 [ V_12 ] ; V_12 ++ ) {
V_13 = F_8 ( V_2 , V_14 [ V_12 ] ) ;
if ( V_13 )
goto error;
}
return 0 ;
error:
while ( -- V_12 >= 0 )
F_9 ( V_2 , V_14 [ V_12 ] ) ;
return V_13 ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_14 [ V_12 ] ; V_12 ++ )
F_9 ( V_2 , V_14 [ V_12 ] ) ;
}
