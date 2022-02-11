int F_1 ( struct V_1 * V_2 , long V_3 )
{
if ( ! V_2 || V_3 < - 1 ) {
F_2 ( 1 , L_1 , V_4 ) ;
return - V_5 ;
} ;
if ( V_3 == - 1 )
F_3 ( L_2
L_3 , F_4 ( V_2 ) ) ;
else
F_3 ( L_4
L_5 , F_4 ( V_2 ) , V_3 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_6 , unsigned long V_7 )
{
if ( ! V_2 || ( V_6 != V_8 &&
V_6 != V_9 ) ) {
F_2 ( 1 , L_1 , V_4 ) ;
return - V_5 ;
} ;
if ( V_7 == 0 )
F_3 ( L_6
L_7 , F_4 ( V_2 ) , V_6 ) ;
else
F_3 ( L_8
L_9 ,
F_4 ( V_2 ) , V_6 , V_7 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_10 , struct V_1 * V_2 ,
long V_3 )
{
if ( ! V_10 || ! V_2 || V_3 < - 1 ) {
F_2 ( 1 , L_1 , V_4 ) ;
return - V_5 ;
} ;
if ( V_3 == - 1 )
F_3 ( L_10
L_3 , F_4 ( V_2 ) ) ;
else
F_3 ( L_11
L_5 , F_4 ( V_2 ) , V_3 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , long V_3 )
{
if ( ! V_2 || V_3 < - 1 ) {
F_2 ( 1 , L_1 , V_4 ) ;
return - V_5 ;
} ;
if ( V_3 == - 1 )
F_3 ( L_12
L_3 , F_4 ( V_2 ) ) ;
else
F_3 ( L_13
L_5 , F_4 ( V_2 ) , V_3 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , struct V_11 * V_12 , long V_7 )
{
if ( ! V_2 || ! V_12 || V_7 < 0 ) {
F_2 ( 1 , L_1 , V_4 ) ;
return - V_5 ;
}
if ( V_7 == 0 )
F_3 ( L_14
L_3 , F_4 ( V_2 ) ) ;
else
F_3 ( L_15
L_16 , F_4 ( V_2 ) , V_7 ) ;
return 0 ;
}
const struct V_13 * F_9 ( void )
{
F_3 ( L_17 ) ;
return NULL ;
}
void F_10 ( T_1 V_14 )
{
if ( V_14 == 0 ) {
F_11 ( 1 ) ;
return;
}
F_3 ( L_18 , V_14 ) ;
}
T_1 F_12 ( void )
{
F_3 ( L_19 ) ;
return 0 ;
}
struct V_15 * * F_13 ( void )
{
F_3 ( L_20 ) ;
return NULL ;
}
void F_14 ( unsigned long V_16 )
{
if ( V_16 == 0 ) {
F_11 ( 1 ) ;
return;
}
F_3 ( L_21 ,
V_16 ) ;
}
unsigned long F_15 ( void )
{
F_3 ( L_22 ) ;
return 0 ;
}
void F_16 ( void )
{
V_17 = true ;
}
void F_17 ( void )
{
V_17 = false ;
}
T_2 F_18 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_19 ( V_2 ) ;
T_2 V_20 ;
if ( F_11 ( ! V_2 ) )
return 0 ;
if ( V_2 -> V_21 == & V_22 ) {
V_20 = F_20 ( V_19 ) ;
} else {
F_21 ( V_17 , L_23 ,
F_4 ( V_2 ) ) ;
if ( V_17 )
V_23 ++ ;
V_20 = V_23 ;
}
F_3 ( L_24 ,
F_4 ( V_2 ) , V_20 ) ;
return V_20 ;
}
T_2 F_18 ( struct V_1 * V_2 )
{
return V_23 ;
}
int T_3 F_22 ( void )
{
return 0 ;
}
int T_3 F_23 ( void )
{
return 0 ;
}
void F_24 ( void )
{
}
