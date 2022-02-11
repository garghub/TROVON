static char T_1 * F_1 ( unsigned int V_1 , unsigned int V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_2 ) ;
if ( V_5 && V_5 -> V_6 )
return V_5 -> V_6 + ( F_3 ( V_2 ) | ( V_3 << 12 ) ) ;
return NULL ;
}
static int F_4 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_7 , int V_8 , T_2 * V_9 )
{
char T_1 * V_10 ;
if ( F_5 ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_7 > 4095 ) ) ) {
V_11: * V_9 = - 1 ;
return - V_12 ;
}
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( ! V_10 )
goto V_11;
switch ( V_8 ) {
case 1 :
* V_9 = F_6 ( V_10 + V_7 ) ;
break;
case 2 :
* V_9 = F_7 ( V_10 + V_7 ) ;
break;
case 4 :
* V_9 = F_8 ( V_10 + V_7 ) ;
break;
}
return 0 ;
}
static int F_9 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_7 , int V_8 , T_2 V_9 )
{
char T_1 * V_10 ;
if ( F_5 ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_7 > 4095 ) ) )
return - V_12 ;
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( ! V_10 )
return - V_12 ;
switch ( V_8 ) {
case 1 :
F_10 ( V_10 + V_7 , V_9 ) ;
break;
case 2 :
F_11 ( V_10 + V_7 , V_9 ) ;
break;
case 4 :
F_12 ( V_10 + V_7 , V_9 ) ;
break;
}
return 0 ;
}
static void T_1 * T_3 F_13 ( struct V_4 * V_5 )
{
void T_1 * V_10 ;
T_4 V_13 , V_14 ;
int V_15 ;
V_13 = V_5 -> V_16 + F_3 ( V_5 -> V_17 ) ;
V_15 = V_5 -> V_18 - V_5 -> V_17 + 1 ;
V_14 = F_3 ( V_15 ) ;
V_10 = F_14 ( V_13 , V_14 ) ;
if ( V_10 )
V_10 -= F_3 ( V_5 -> V_17 ) ;
return V_10 ;
}
int T_3 F_15 ( void )
{
struct V_4 * V_5 ;
F_16 (cfg, &pci_mmcfg_list, list) {
V_5 -> V_6 = F_13 ( V_5 ) ;
if ( ! V_5 -> V_6 ) {
F_17 (KERN_ERR PREFIX L_1 ,
&cfg->res) ;
F_18 () ;
return 0 ;
}
}
V_19 = & V_20 ;
return 1 ;
}
void T_3 F_18 ( void )
{
struct V_4 * V_5 ;
F_16 (cfg, &pci_mmcfg_list, list) {
if ( V_5 -> V_6 ) {
F_19 ( V_5 -> V_6 + F_3 ( V_5 -> V_17 ) ) ;
V_5 -> V_6 = NULL ;
}
}
}
