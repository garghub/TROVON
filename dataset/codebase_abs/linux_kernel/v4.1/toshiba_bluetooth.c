static int F_1 ( T_1 V_1 )
{
T_2 V_2 ;
T_3 V_3 ;
V_2 = F_2 ( V_1 , L_1 , NULL , & V_3 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_2 ) ;
return - V_4 ;
} else if ( ! V_3 ) {
F_5 ( L_3 ) ;
return - V_5 ;
}
return 0 ;
}
static int F_6 ( T_1 V_1 )
{
T_2 V_2 ;
T_3 V_6 ;
V_2 = F_2 ( V_1 , L_4 , NULL , & V_6 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_5 ) ;
return - V_4 ;
}
F_5 ( L_6 , V_6 ) ;
return V_6 ;
}
static int F_7 ( T_1 V_1 )
{
T_2 V_2 ;
bool V_7 ;
bool V_8 ;
bool V_9 ;
int V_6 ;
V_6 = F_6 ( V_1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_7 = ( V_6 & V_10 ) ? true : false ;
V_8 = ( V_6 & V_11 ) ? true : false ;
V_9 = ( V_6 & V_12 ) ? true : false ;
if ( ! V_7 )
return 0 ;
if ( V_8 || V_9 )
return 0 ;
V_2 = F_8 ( V_1 , L_7 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_8 ) ;
return - V_4 ;
}
V_2 = F_8 ( V_1 , L_9 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_10 ) ;
return - V_4 ;
}
return 0 ;
}
static int F_9 ( T_1 V_1 )
{
T_2 V_2 ;
V_2 = F_8 ( V_1 , L_11 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_12 ) ;
return - V_4 ;
}
V_2 = F_8 ( V_1 , L_13 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_14 ) ;
return - V_4 ;
}
return 0 ;
}
static void F_10 ( struct V_13 * V_14 , T_4 V_15 )
{
F_7 ( V_14 -> V_1 ) ;
}
static int F_11 ( struct V_14 * V_16 )
{
return F_7 ( F_12 ( V_16 ) -> V_1 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
int V_2 ;
V_2 = F_1 ( V_14 -> V_1 ) ;
if ( V_2 )
return V_2 ;
F_5 ( L_15 ) ;
V_2 = F_7 ( V_14 -> V_1 ) ;
if ( V_2 )
return V_2 ;
return V_2 ;
}
static int F_14 ( struct V_13 * V_14 )
{
return F_9 ( V_14 -> V_1 ) ;
}
