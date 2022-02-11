static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( L_1 ) ;
F_4 ( V_2 , sizeof( * V_2 ) ) ;
if ( ! V_4 )
return;
F_5 ( L_2 ,
F_6 ( V_4 -> V_6 ) , V_2 -> V_7 , V_2 -> V_5 ) ;
}
void F_7 ( void * V_8 )
{
if ( F_8 () )
F_1 ( V_8 ) ;
}
static void F_9 ( struct V_9 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_10 * V_6 = V_4 ? V_4 -> V_6 : NULL ;
int V_11 ;
F_10 ( L_3 ,
V_6 ? F_6 ( V_6 ) : L_4 , V_2 -> V_7 , V_2 -> V_5 ) ;
F_3 ( L_5 ) ;
F_4 ( V_2 , sizeof( * V_2 ) ) ;
switch ( V_2 -> V_7 ) {
case 0x0301 :
if ( ! V_4 || V_4 -> V_12 != V_13 )
break;
V_4 -> V_12 = V_14 ;
V_4 -> V_15 = V_2 -> V_15 ;
V_11 = F_11 ( V_4 ) ;
if ( V_11 )
break;
F_12 ( V_4 -> V_16 ) ;
break;
case 0x0302 :
if ( ! V_4 )
F_13 ( V_2 -> V_5 , V_2 -> V_15 , 0 ) ;
break;
case 0x0303 :
if ( V_6 )
F_14 ( V_6 ) ;
V_11 = F_15 ( V_4 ) ;
if ( V_11 )
break;
V_11 = F_16 ( V_4 -> V_5 ) ;
F_17 ( 3 , L_6 , V_4 -> V_5 , V_11 ) ;
if ( ! V_11 )
V_4 -> V_12 = V_13 ;
break;
case 0x0304 :
if ( V_6 ) {
V_6 -> V_17 = V_18 ;
F_14 ( V_6 ) ;
}
V_4 -> V_15 = V_2 -> V_15 ;
F_15 ( V_4 ) ;
V_4 -> V_12 = V_13 ;
break;
case 0x0306 :
F_18 () ;
break;
case 0x0308 :
if ( ! V_4 )
break;
F_19 ( V_4 -> V_16 ) ;
F_20 ( V_4 -> V_16 ) ;
break;
default:
break;
}
}
void F_21 ( void * V_8 )
{
if ( F_8 () )
F_9 ( V_8 ) ;
}
