static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
const char * V_8 ;
int V_9 ;
int V_10 = 0 ;
V_7 = & F_2 ( V_2 ) -> V_11 ;
V_8 = F_3 ( V_7 -> V_2 . V_12 , L_1 , & V_9 ) ;
if ( ! V_8 ) {
* V_5 = '\0' ;
return 0 ;
}
while ( V_9 > 0 ) {
int V_13 ;
V_10 += sprintf ( V_5 , L_2 , V_8 ) ;
V_5 += V_10 ;
V_13 = strlen ( V_8 ) + 1 ;
V_8 += V_13 ;
V_9 -= V_13 ;
}
return V_10 ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return F_5 ( V_2 , V_5 , V_14 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_11 ;
V_11 = F_7 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_11 -> V_2 . V_12 -> V_15 ) ;
}
