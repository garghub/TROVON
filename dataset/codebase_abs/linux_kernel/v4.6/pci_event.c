static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = NULL ;
F_3 ( L_1 ) ;
F_4 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_4 )
V_7 = F_5 ( V_4 -> V_8 , V_9 ) ;
F_6 ( L_2 ,
V_7 ? F_7 ( V_7 ) : L_3 , V_2 -> V_10 , V_2 -> V_5 ) ;
if ( ! V_7 )
return;
V_7 -> V_11 = V_12 ;
F_8 ( V_7 ) ;
}
void F_9 ( void * V_13 )
{
if ( F_10 () )
F_1 ( V_13 ) ;
}
static void F_11 ( struct V_14 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = NULL ;
int V_15 ;
if ( V_4 )
V_7 = F_5 ( V_4 -> V_8 , V_9 ) ;
F_12 ( L_4 ,
V_7 ? F_7 ( V_7 ) : L_3 , V_2 -> V_10 , V_2 -> V_5 ) ;
F_3 ( L_5 ) ;
F_4 ( V_2 , sizeof( * V_2 ) ) ;
switch ( V_2 -> V_10 ) {
case 0x0301 :
if ( ! V_4 ) {
V_15 = F_13 ( V_2 -> V_5 , V_2 -> V_16 , 0 ) ;
if ( V_15 )
break;
V_4 = F_2 ( V_2 -> V_5 ) ;
}
if ( ! V_4 || V_4 -> V_17 != V_18 )
break;
V_4 -> V_17 = V_19 ;
V_4 -> V_16 = V_2 -> V_16 ;
V_15 = F_14 ( V_4 ) ;
if ( V_15 )
break;
F_15 () ;
F_16 ( V_4 -> V_8 ) ;
F_17 () ;
break;
case 0x0302 :
if ( ! V_4 )
F_13 ( V_2 -> V_5 , V_2 -> V_16 , 0 ) ;
break;
case 0x0303 :
if ( V_7 )
F_18 ( V_7 ) ;
V_15 = F_19 ( V_4 ) ;
if ( V_15 )
break;
V_15 = F_20 ( V_4 -> V_5 ) ;
F_21 ( 3 , L_6 , V_4 -> V_5 , V_15 ) ;
if ( ! V_15 )
V_4 -> V_17 = V_18 ;
break;
case 0x0304 :
if ( V_7 ) {
V_7 -> V_11 = V_12 ;
F_18 ( V_7 ) ;
}
V_4 -> V_16 = V_2 -> V_16 ;
F_19 ( V_4 ) ;
V_4 -> V_17 = V_18 ;
break;
case 0x0306 :
F_22 () ;
break;
case 0x0308 :
if ( ! V_4 )
break;
F_23 ( V_4 -> V_8 ) ;
F_24 ( V_4 -> V_8 ) ;
break;
default:
break;
}
if ( V_7 )
F_8 ( V_7 ) ;
}
void F_25 ( void * V_13 )
{
if ( F_10 () )
F_11 ( V_13 ) ;
}
