static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 ? V_4 -> V_7 : NULL ;
F_3 ( L_1 ) ;
F_4 ( V_2 , sizeof( * V_2 ) ) ;
F_5 ( L_2 ,
V_7 ? F_6 ( V_7 ) : L_3 , V_2 -> V_8 , V_2 -> V_5 ) ;
if ( ! V_7 )
return;
V_7 -> V_9 = V_10 ;
}
void F_7 ( void * V_11 )
{
if ( F_8 () )
F_1 ( V_11 ) ;
}
static void F_9 ( struct V_12 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 ? V_4 -> V_7 : NULL ;
int V_13 ;
F_10 ( L_4 ,
V_7 ? F_6 ( V_7 ) : L_3 , V_2 -> V_8 , V_2 -> V_5 ) ;
F_3 ( L_5 ) ;
F_4 ( V_2 , sizeof( * V_2 ) ) ;
switch ( V_2 -> V_8 ) {
case 0x0301 :
if ( ! V_4 ) {
V_13 = F_11 ( V_2 -> V_5 , V_2 -> V_14 , 0 ) ;
if ( V_13 )
break;
V_4 = F_2 ( V_2 -> V_5 ) ;
}
if ( ! V_4 || V_4 -> V_15 != V_16 )
break;
V_4 -> V_15 = V_17 ;
V_4 -> V_14 = V_2 -> V_14 ;
V_13 = F_12 ( V_4 ) ;
if ( V_13 )
break;
F_13 () ;
F_14 ( V_4 -> V_18 ) ;
F_15 () ;
break;
case 0x0302 :
if ( ! V_4 )
F_11 ( V_2 -> V_5 , V_2 -> V_14 , 0 ) ;
break;
case 0x0303 :
if ( V_7 )
F_16 ( V_7 ) ;
V_13 = F_17 ( V_4 ) ;
if ( V_13 )
break;
V_13 = F_18 ( V_4 -> V_5 ) ;
F_19 ( 3 , L_6 , V_4 -> V_5 , V_13 ) ;
if ( ! V_13 )
V_4 -> V_15 = V_16 ;
break;
case 0x0304 :
if ( V_7 ) {
V_7 -> V_9 = V_10 ;
F_16 ( V_7 ) ;
}
V_4 -> V_14 = V_2 -> V_14 ;
F_17 ( V_4 ) ;
V_4 -> V_15 = V_16 ;
break;
case 0x0306 :
F_20 () ;
break;
case 0x0308 :
if ( ! V_4 )
break;
F_21 ( V_4 -> V_18 ) ;
F_22 ( V_4 -> V_18 ) ;
break;
default:
break;
}
}
void F_23 ( void * V_11 )
{
if ( F_8 () )
F_9 ( V_11 ) ;
}
