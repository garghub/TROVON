int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 . V_6 . V_7 ) ;
if ( V_4 != 0 && V_4 <= V_2 -> V_5 . V_6 . V_8 ) {
V_4 -- ;
V_2 -> V_5 . V_6 . V_7 &= ~ ( 1u << V_4 ) ;
* V_3 = V_2 -> V_5 . V_6 . V_9 + V_4 ;
return 0 ;
}
return - V_10 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_5 . V_6 . V_7 |= 1u << ( V_3 - V_2 -> V_5 . V_6 . V_9 ) ;
}
void F_4 ( unsigned * V_11 , unsigned V_12 , unsigned V_13 )
{
unsigned V_14 , V_15 , V_16 ;
const char * V_17 ;
memset ( V_11 , 0 , sizeof( * V_11 ) * V_12 * V_13 ) ;
if ( ! V_18 || ! * V_18 )
return;
V_17 = V_18 ;
for (; ; ) {
char * V_19 ;
int V_20 = sscanf ( V_17 , L_1 , & V_14 , & V_15 , & V_16 ) ;
if ( V_20 < 3 ) {
F_5 ( L_2 ) ;
return;
}
if ( V_14 < V_12 && V_15 < V_13 && V_16 < 16 ) {
F_6 ( L_3 , V_14 , V_15 , V_16 ) ;
V_11 [ V_14 * V_13 + V_15 ] |= 1u << V_16 ;
} else {
F_5 ( L_4 ,
V_14 , V_15 , V_16 ) ;
}
V_19 = strchr ( V_17 , ',' ) ;
if ( ! V_19 )
break;
V_17 = V_19 + 1 ;
}
}
void F_7 ( struct V_1 * V_2 )
{
int V_4 , V_21 , V_22 , V_23 ;
for ( V_4 = 0 ; V_4 < V_24 ; ++ V_4 ) {
V_21 = V_4 % V_2 -> V_5 . V_23 . V_25 ;
V_22 = ( V_4 / V_2 -> V_5 . V_23 . V_25 )
% V_2 -> V_5 . V_23 . V_26 ;
V_23 = ( V_4 / V_2 -> V_5 . V_23 . V_25 )
/ V_2 -> V_5 . V_23 . V_26 ;
if ( V_23 >= V_2 -> V_5 . V_23 . V_27 )
break;
if ( 0 ) {
if ( V_23 == 0 && V_21 < 2 )
F_8 ( V_4 , V_2 -> V_5 . V_23 . V_28 ) ;
} else {
if ( V_23 == 0 && V_22 == 0 )
F_8 ( V_4 , V_2 -> V_5 . V_23 . V_28 ) ;
}
}
V_2 -> V_5 . V_29 =
F_9 ( V_2 -> V_5 . V_23 . V_28 , V_24 ) ;
if ( F_10 ( V_2 -> V_5 . V_29 > V_30 ) )
V_2 -> V_5 . V_29 = V_30 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_33 ;
int V_23 , V_22 , V_21 ;
V_33 = V_2 -> V_5 . V_23 . V_27
* V_2 -> V_5 . V_23 . V_26
* V_2 -> V_5 . V_23 . V_25 ;
while ( V_33 -- >= 0 ) {
if ( F_12 ( V_33 , V_2 -> V_5 . V_23 . V_28 ) )
continue;
F_13 ( V_2 , V_33 , & V_23 , & V_22 , & V_21 ) ;
if ( V_23 == 1 && V_22 > 1 )
continue;
V_32 -> V_34 = V_23 + 1 ;
V_32 -> V_22 = V_22 ;
V_32 -> V_21 = V_21 ;
return 0 ;
}
F_14 ( V_2 -> V_35 , L_5 ) ;
return - V_10 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = & V_2 -> V_5 . V_39 ;
int V_40 = 0 ;
F_16 ( & V_39 -> V_41 ) ;
V_40 = F_17 ( V_2 , & V_2 -> V_42 . V_43 ) ;
if ( V_40 )
return V_40 ;
V_32 -> V_2 = NULL ;
V_32 -> V_44 = NULL ;
V_32 -> V_45 = true ;
V_32 -> V_46 = V_47 ;
V_40 = F_11 ( V_2 , V_32 ) ;
if ( V_40 )
return V_40 ;
V_32 -> V_48 = V_39 -> V_48 ;
sprintf ( V_32 -> V_49 , L_6 , V_32 -> V_34 , V_32 -> V_22 , V_32 -> V_21 ) ;
V_40 = F_18 ( V_2 , V_32 , 1024 ,
V_37 , V_50 ) ;
if ( V_40 )
F_19 ( V_2 -> V_35 , L_7 , V_40 ) ;
return V_40 ;
}
void F_20 ( struct V_31 * V_32 ,
struct V_36 * V_37 )
{
F_21 ( V_32 -> V_2 , V_32 -> V_2 -> V_42 . V_43 ) ;
F_22 ( V_32 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = & V_2 -> V_5 . V_39 ;
F_24 ( & V_39 -> V_51 , & V_39 -> V_48 , NULL ) ;
}
int F_25 ( struct V_1 * V_2 ,
unsigned V_52 )
{
int V_40 ;
T_2 * V_53 ;
struct V_38 * V_39 = & V_2 -> V_5 . V_39 ;
V_40 = F_26 ( V_2 , V_52 , V_54 ,
V_55 , & V_39 -> V_51 ,
& V_39 -> V_48 , ( void * * ) & V_53 ) ;
if ( V_40 ) {
F_19 ( V_2 -> V_35 , L_8 , V_40 ) ;
return V_40 ;
}
memset ( V_53 , 0 , V_52 ) ;
V_40 = F_27 ( V_39 -> V_51 , true ) ;
if ( F_28 ( V_40 != 0 ) )
F_19 ( V_2 -> V_35 , L_9 , V_40 ) ;
F_29 ( V_39 -> V_51 ) ;
F_30 ( V_39 -> V_51 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 ,
unsigned V_56 )
{
struct V_31 * V_32 = NULL ;
int V_40 , V_4 ;
V_32 = & V_2 -> V_5 . V_39 . V_32 ;
if ( ! V_32 -> V_57 ) {
V_40 = F_26 ( V_2 , V_56 , V_54 ,
V_55 , & V_32 -> V_57 ,
& V_32 -> V_58 , & V_32 -> V_59 ) ;
if ( V_40 ) {
F_19 ( V_2 -> V_35 , L_10 , V_40 ) ;
return V_40 ;
}
V_2 -> V_5 . V_23 . V_60 [ V_30 ] = F_32 ( V_56 , V_61 ) ;
if ( ! V_2 -> V_5 . V_23 . V_60 [ V_30 ] )
F_19 ( V_2 -> V_35 , L_11 , V_32 -> V_49 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_29 ; V_4 ++ ) {
V_32 = & V_2 -> V_5 . V_62 [ V_4 ] ;
if ( ! V_32 -> V_57 ) {
V_40 = F_26 ( V_2 , V_56 , V_54 ,
V_55 , & V_32 -> V_57 ,
& V_32 -> V_58 , & V_32 -> V_59 ) ;
if ( V_40 ) {
F_19 ( V_2 -> V_35 , L_10 , V_40 ) ;
return V_40 ;
}
V_2 -> V_5 . V_23 . V_60 [ V_4 ] = F_32 ( V_56 , V_61 ) ;
if ( ! V_2 -> V_5 . V_23 . V_60 [ V_4 ] )
F_19 ( V_2 -> V_35 , L_11 , V_32 -> V_49 ) ;
}
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = NULL ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_29 ; V_4 ++ ) {
V_32 = & V_2 -> V_5 . V_62 [ V_4 ] ;
F_34 ( V_2 -> V_5 . V_23 . V_60 [ V_4 ] ) ;
F_24 ( & V_32 -> V_57 ,
& V_32 -> V_58 ,
& V_32 -> V_59 ) ;
}
V_32 = & V_2 -> V_5 . V_39 . V_32 ;
F_34 ( V_2 -> V_5 . V_23 . V_60 [ V_30 ] ) ;
F_24 ( & V_32 -> V_57 ,
& V_32 -> V_58 ,
& V_32 -> V_59 ) ;
}
