void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
F_3 ( L_1 ) ;
F_4 ( V_3 , sizeof( * V_3 ) ) ;
if ( ! V_5 )
return;
F_5 ( L_2 ,
F_6 ( V_5 -> V_7 ) , V_3 -> V_8 , V_3 -> V_6 ) ;
}
void F_7 ( void * V_1 )
{
struct V_9 * V_3 = V_1 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_10 * V_7 = V_5 ? V_5 -> V_7 : NULL ;
int V_11 ;
F_8 ( L_3 ,
V_7 ? F_6 ( V_7 ) : L_4 , V_3 -> V_8 , V_3 -> V_6 ) ;
F_3 ( L_5 ) ;
F_4 ( V_3 , sizeof( * V_3 ) ) ;
switch ( V_3 -> V_8 ) {
case 0x0301 :
if ( ! V_5 || V_5 -> V_12 == V_13 )
break;
V_5 -> V_12 = V_13 ;
V_5 -> V_14 = V_3 -> V_14 ;
V_11 = F_9 ( V_5 ) ;
if ( V_11 )
break;
F_10 ( V_5 -> V_15 ) ;
break;
case 0x0302 :
F_11 ( V_3 -> V_6 , V_3 -> V_14 , 0 ) ;
break;
case 0x0303 :
if ( V_7 )
F_12 ( V_7 ) ;
V_11 = F_13 ( V_5 ) ;
if ( V_11 )
break;
V_11 = F_14 ( V_5 -> V_6 ) ;
F_15 ( 3 , L_6 , V_5 -> V_6 , V_11 ) ;
if ( ! V_11 )
V_5 -> V_12 = V_16 ;
break;
case 0x0304 :
if ( V_7 )
F_12 ( V_7 ) ;
V_5 -> V_14 = V_3 -> V_14 ;
F_13 ( V_5 ) ;
V_5 -> V_12 = V_16 ;
break;
case 0x0306 :
F_16 () ;
break;
case 0x0308 :
F_17 ( V_5 -> V_15 ) ;
F_18 ( V_5 -> V_15 ) ;
break;
default:
break;
}
}
