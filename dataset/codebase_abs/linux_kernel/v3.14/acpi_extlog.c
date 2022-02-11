static struct V_1 * F_1 ( int V_2 , int V_3 )
{
int V_4 ;
T_1 V_5 ;
struct V_1 * V_6 ;
F_2 ( V_2 < 0 ) ;
V_4 = F_3 ( V_2 , V_3 ) ;
V_5 = F_4 ( V_4 ) ;
if ( ( V_5 & V_7 ) == 0 )
return NULL ;
V_5 &= V_8 ;
V_6 = (struct V_1 * ) F_5 ( V_5 ) ;
if ( V_6 -> V_9 == 0 )
return NULL ;
return V_6 ;
}
static void F_6 ( const char * V_10 ,
struct V_1 * V_6 , int V_2 )
{
static T_2 V_11 ;
unsigned int V_12 ;
char V_13 [ 64 ] ;
if ( ! V_10 ) {
if ( V_6 -> V_14 <= V_15 )
V_10 = V_16 ;
else
V_10 = V_17 ;
}
V_12 = F_7 ( & V_11 ) ;
snprintf ( V_13 , sizeof( V_13 ) , L_1 , V_10 , V_12 ) ;
F_8 ( L_2Hardware error detected on CPU%d\nL_3\\_SBL_4L1 Directory is invalid at physical %llx\nL_5Not loading eMCA, error reporting force-enabled through EDAC.\nL_6L1 DIR HDRL_7L1 TableL_8Elog TableL_9Extended error log disabled because of problems parsing f/w tables\nL_10Chen, Gong <gong.chen@intel.com>L_11Extended MCA Error Log DriverL_12GPL"
