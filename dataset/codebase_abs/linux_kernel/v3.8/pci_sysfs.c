static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 , struct V_8 , V_2 ) ) ;
sprintf ( V_5 , L_1 , V_7 -> V_9 ) ;
return strlen ( V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 , struct V_8 , V_2 ) ) ;
sprintf ( V_5 , L_1 , V_7 -> V_10 ) ;
return strlen ( V_5 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 , struct V_8 , V_2 ) ) ;
sprintf ( V_5 , L_2 , V_7 -> V_11 ) ;
return strlen ( V_5 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 , struct V_8 , V_2 ) ) ;
sprintf ( V_5 , L_3 , V_7 -> V_12 ) ;
return strlen ( V_5 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_13 , V_14 = 0 ;
for ( V_13 = 0 ; V_15 [ V_13 ] ; V_13 ++ ) {
V_14 = F_8 ( V_2 , V_15 [ V_13 ] ) ;
if ( V_14 )
goto error;
}
return 0 ;
error:
while ( -- V_13 >= 0 )
F_9 ( V_2 , V_15 [ V_13 ] ) ;
return V_14 ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_15 [ V_13 ] ; V_13 ++ )
F_9 ( V_2 , V_15 [ V_13 ] ) ;
}
