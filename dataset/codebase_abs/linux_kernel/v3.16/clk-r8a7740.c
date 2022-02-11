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
switch ( V_13 & ( F_2 ( 2 ) | F_2 ( 1 ) ) ) {
case F_2 ( 1 ) | F_2 ( 2 ) :
V_9 = F_3 ( V_3 , 0 ) ;
div = 2048 ;
break;
case F_2 ( 2 ) :
V_9 = F_3 ( V_3 , 0 ) ;
div = 1024 ;
break;
default:
V_9 = F_3 ( V_3 , 2 ) ;
break;
}
} else if ( ! strcmp ( V_6 , L_2 ) ) {
V_9 = F_3 ( V_3 , 0 ) ;
if ( V_13 & F_2 ( 1 ) )
div = 2 ;
} else if ( ! strcmp ( V_6 , L_3 ) ) {
T_2 V_14 = F_4 ( V_5 -> V_11 + V_15 ) ;
V_9 = L_2 ;
V_12 = ( ( V_14 >> 24 ) & 0x7f ) + 1 ;
} else if ( ! strcmp ( V_6 , L_4 ) ) {
T_2 V_14 = F_4 ( V_5 -> V_11 + V_16 ) ;
V_9 = L_2 ;
V_12 = ( ( V_14 >> 24 ) & 0x7f ) + 1 ;
div = 2 ;
} else if ( ! strcmp ( V_6 , L_5 ) ) {
T_2 V_14 = F_4 ( V_5 -> V_11 + V_17 ) ;
V_9 = L_2 ;
V_12 = ( ( V_14 >> 24 ) & 0x3f ) + 1 ;
} else if ( ! strcmp ( V_6 , L_6 ) ) {
T_2 V_14 = F_4 ( V_5 -> V_11 + V_18 ) ;
if ( V_14 & F_2 ( 7 ) )
V_9 = F_3 ( V_3 , 1 ) ;
else
V_9 = L_2 ;
if ( ! ( V_14 & F_2 ( 6 ) ) )
div = 2 ;
} else {
struct V_19 * V_20 ;
for ( V_20 = V_21 ; V_20 -> V_6 ; V_20 ++ ) {
if ( ! strcmp ( V_6 , V_20 -> V_6 ) ) {
V_9 = L_4 ;
V_8 = V_22 ;
V_11 = V_20 -> V_11 ;
V_10 = V_20 -> V_10 ;
break;
}
}
if ( ! V_20 -> V_6 )
return F_5 ( - V_23 ) ;
}
if ( ! V_8 ) {
return F_6 ( NULL , V_6 , V_9 , 0 ,
V_12 , div ) ;
} else {
return F_7 ( NULL , V_6 , V_9 , 0 ,
V_5 -> V_11 + V_11 , V_10 , 4 , 0 ,
V_8 , & V_5 -> V_24 ) ;
}
}
static void T_1 F_8 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * * V_25 ;
unsigned int V_26 ;
int V_27 ;
if ( F_9 ( V_3 , L_7 , & V_13 ) )
F_10 ( L_8 , V_28 ) ;
V_27 = F_11 ( V_3 , L_9 ) ;
if ( V_27 < 0 ) {
F_12 ( L_10 , V_28 ) ;
return;
}
V_5 = F_13 ( sizeof( * V_5 ) , V_29 ) ;
V_25 = F_13 ( V_27 * sizeof( * V_25 ) , V_29 ) ;
if ( V_5 == NULL || V_25 == NULL ) {
return;
}
F_14 ( & V_5 -> V_24 ) ;
V_5 -> V_30 . V_25 = V_25 ;
V_5 -> V_30 . V_31 = V_27 ;
V_5 -> V_11 = F_15 ( V_3 , 0 ) ;
if ( F_16 ( V_5 -> V_11 == NULL ) )
return;
for ( V_26 = 0 ; V_26 < V_27 ; ++ V_26 ) {
const char * V_6 ;
struct V_1 * V_1 ;
F_17 ( V_3 , L_9 , V_26 ,
& V_6 ) ;
V_1 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( F_18 ( V_1 ) )
F_12 ( L_11 ,
V_28 , V_3 -> V_6 , V_6 , F_19 ( V_1 ) ) ;
else
V_5 -> V_30 . V_25 [ V_26 ] = V_1 ;
}
F_20 ( V_3 , V_32 , & V_5 -> V_30 ) ;
}
