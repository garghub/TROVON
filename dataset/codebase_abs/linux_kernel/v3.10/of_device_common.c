unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 || V_3 >= V_5 -> V_6 . V_7 )
return 0 ;
return V_5 -> V_6 . V_8 [ V_3 ] ;
}
int F_3 ( struct V_1 * V_2 , int V_3 ,
struct V_9 * V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 || V_3 >= V_5 -> V_11 )
return - V_12 ;
memcpy ( V_10 , & V_5 -> V_6 . V_9 [ V_3 ] , sizeof( * V_10 ) ) ;
return 0 ;
}
void T_1 * F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
if ( ! V_5 || V_3 >= V_5 -> V_11 )
return NULL ;
V_10 = & V_5 -> V_6 . V_9 [ V_3 ] ;
return F_5 ( V_10 , 0 , F_6 ( V_10 ) , ( char * ) V_10 -> V_13 ) ;
}
void F_7 ( struct V_4 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_17 . V_6 ;
struct V_1 * V_18 = V_14 -> V_17 . V_19 ;
struct V_1 * V_20 ;
for ( V_20 = V_18 -> V_21 ; V_20 ; V_20 = V_20 -> V_22 ) {
struct V_4 * V_5 = F_2 ( V_20 ) ;
V_5 -> V_17 . V_6 . V_23 = V_16 -> V_23 ;
V_5 -> V_17 . V_6 . V_24 = V_16 -> V_24 ;
V_5 -> V_17 . V_6 . V_25 = V_16 -> V_25 ;
V_5 -> V_17 . V_6 . V_26 = V_16 -> V_26 ;
if ( V_20 -> V_21 )
F_7 ( V_5 ) ;
}
}
static void F_8 ( struct V_1 * V_20 , int * V_27 , int * V_28 )
{
if ( V_27 )
* V_27 = F_9 ( V_20 ) ;
if ( V_28 )
* V_28 = F_10 ( V_20 ) ;
}
void F_11 ( struct V_1 * V_17 , int * V_27 , int * V_28 )
{
F_8 ( V_17 , V_27 , V_28 ) ;
}
int F_12 ( const T_2 * V_29 , const T_2 * V_30 ,
const T_2 * V_31 , int V_32 , int V_33 )
{
T_3 V_34 = F_13 ( V_29 , V_32 ) ;
T_3 V_35 = F_13 ( V_30 , V_32 ) ;
if ( V_34 < V_35 )
return 1 ;
V_35 += F_13 ( V_31 , V_33 ) ;
if ( V_34 >= V_35 )
return 1 ;
return 0 ;
}
int F_14 ( T_2 * V_29 , const T_2 * V_36 , int V_32 , int V_33 , int V_37 )
{
T_2 V_38 [ V_39 ] ;
int V_40 ;
if ( V_33 > 2 ) {
F_15 ( L_1 , V_33 ) ;
return - V_12 ;
}
if ( F_12 ( V_29 , V_36 , V_36 + V_32 + V_37 , V_32 , V_33 ) )
return - V_12 ;
memcpy ( V_38 , V_36 + V_32 , V_37 * 4 ) ;
for ( V_40 = 0 ; V_40 < V_32 ; V_40 ++ )
V_38 [ V_37 - 1 - V_40 ] +=
( V_29 [ V_32 - 1 - V_40 ] -
V_36 [ V_32 - 1 - V_40 ] ) ;
memcpy ( V_29 , V_38 , V_37 * 4 ) ;
return 0 ;
}
unsigned long F_16 ( const T_2 * V_29 , unsigned long V_41 )
{
if ( V_41 )
return V_41 ;
return V_42 ;
}
int F_17 ( struct V_1 * V_43 )
{
struct V_1 * V_20 = V_43 ;
while ( V_20 ) {
if ( ! strcmp ( V_20 -> V_13 , L_2 ) ||
! strcmp ( V_20 -> V_13 , L_3 ) )
return 1 ;
if ( F_18 ( V_20 , L_4 , NULL ) != NULL )
break;
V_20 = V_20 -> V_44 ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_21 , int * V_27 , int * V_28 )
{
if ( V_27 )
* V_27 = 2 ;
if ( V_28 )
* V_28 = 1 ;
}
