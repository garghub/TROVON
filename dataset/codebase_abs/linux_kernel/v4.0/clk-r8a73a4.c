static struct V_1 * T_1
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 )
{
const struct V_7 * V_8 = NULL ;
const char * V_9 ;
unsigned int V_10 , V_11 ;
unsigned int V_12 = 1 ;
unsigned int div = 1 ;
if ( ! strcmp ( V_6 , L_1 ) ) {
T_2 V_13 = F_2 ( V_5 -> V_11 + V_14 ) ;
switch ( ( V_13 >> 28 ) & 3 ) {
case 0 :
V_9 = F_3 ( V_3 , 0 ) ;
break;
case 1 :
V_9 = F_3 ( V_3 , 0 ) ;
div = 2 ;
break;
case 2 :
V_9 = F_3 ( V_3 , 1 ) ;
break;
case 3 :
V_9 = F_3 ( V_3 , 1 ) ;
div = 2 ;
break;
}
} else if ( ! strcmp ( V_6 , L_2 ) ) {
T_2 V_15 = F_2 ( V_5 -> V_11 + V_16 ) ;
V_9 = L_1 ;
V_12 = ( ( V_15 >> 24 ) & 0x7f ) + 1 ;
if ( V_15 & F_4 ( 20 ) )
div = 2 ;
} else if ( ! strcmp ( V_6 , L_3 ) ) {
T_2 V_15 = F_2 ( V_5 -> V_11 + V_17 ) ;
V_9 = L_1 ;
V_12 = ( ( V_15 >> 24 ) & 0x7f ) + 1 ;
if ( V_15 & F_4 ( 7 ) )
div = 2 ;
} else if ( ! strncmp ( V_6 , L_4 , 4 ) ) {
T_2 V_15 , V_18 ;
switch ( V_6 [ 4 ] ) {
case 0 :
V_18 = V_19 ;
break;
case 's' :
V_18 = V_20 ;
break;
case 'h' :
V_18 = V_21 ;
break;
default:
return F_5 ( - V_22 ) ;
}
V_15 = F_2 ( V_5 -> V_11 + V_18 ) ;
switch ( ( V_15 >> 5 ) & 7 ) {
case 0 :
V_9 = L_1 ;
div = 2 ;
break;
case 1 :
V_9 = L_5 ;
div = 2 ;
break;
case 3 :
V_9 = L_5 ;
div = 4 ;
break;
case 4 :
V_9 = L_1 ;
break;
case 5 :
V_9 = L_5 ;
break;
default:
F_6 ( L_6 , V_23 ,
V_6 ) ;
return F_5 ( - V_22 ) ;
}
V_12 = ( ( V_15 >> 24 ) & 0x7f ) + 1 ;
} else if ( ! strcmp ( V_6 , L_7 ) || ! strcmp ( V_6 , L_8 ) ) {
T_2 V_10 = 8 ;
V_9 = L_2 ;
if ( V_6 [ 1 ] == '2' ) {
div = 2 ;
V_10 = 0 ;
}
div *= 32 ;
V_12 = 0x20 - ( ( F_2 ( V_5 -> V_11 + V_24 ) >> V_10 )
& 0x1f ) ;
} else {
struct V_25 * V_26 ;
for ( V_26 = V_27 ; V_26 -> V_6 ; V_26 ++ ) {
if ( ! strcmp ( V_6 , V_26 -> V_6 ) )
break;
}
if ( ! V_26 -> V_6 )
return F_5 ( - V_22 ) ;
V_9 = L_3 ;
V_8 = V_28 ;
V_11 = V_26 -> V_11 ;
V_10 = V_26 -> V_10 ;
}
if ( ! V_8 ) {
return F_7 ( NULL , V_6 , V_9 , 0 ,
V_12 , div ) ;
} else {
return F_8 ( NULL , V_6 , V_9 , 0 ,
V_5 -> V_11 + V_11 , V_10 , 4 , 0 ,
V_8 , & V_5 -> V_29 ) ;
}
}
static void T_1 F_9 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * * V_30 ;
unsigned int V_31 ;
int V_32 ;
V_32 = F_10 ( V_3 , L_9 ) ;
if ( V_32 < 0 ) {
F_11 ( L_10 , V_23 ) ;
return;
}
V_5 = F_12 ( sizeof( * V_5 ) , V_33 ) ;
V_30 = F_13 ( V_32 , sizeof( * V_30 ) , V_33 ) ;
if ( V_5 == NULL || V_30 == NULL ) {
return;
}
F_14 ( & V_5 -> V_29 ) ;
V_5 -> V_34 . V_30 = V_30 ;
V_5 -> V_34 . V_35 = V_32 ;
V_5 -> V_11 = F_15 ( V_3 , 0 ) ;
if ( F_16 ( V_5 -> V_11 == NULL ) )
return;
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 ) {
const char * V_6 ;
struct V_1 * V_1 ;
F_17 ( V_3 , L_9 , V_31 ,
& V_6 ) ;
V_1 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( F_18 ( V_1 ) )
F_11 ( L_11 ,
V_23 , V_3 -> V_6 , V_6 , F_19 ( V_1 ) ) ;
else
V_5 -> V_34 . V_30 [ V_31 ] = V_1 ;
}
F_20 ( V_3 , V_36 , & V_5 -> V_34 ) ;
}
