int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_6 ;
F_2 ( & V_2 -> V_7 ) ;
F_3 ( & V_2 -> V_8 , V_9 ) ;
F_4 ( & V_2 -> V_10 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( ! F_7 ( & V_2 -> V_7 ) ) ;
F_8 ( & V_2 -> V_8 ) ;
}
int F_9 ( struct V_1 * V_2 , unsigned int V_11 ,
unsigned int V_12 , unsigned int * V_13 )
{
int V_14 ;
F_10 ( & V_2 -> V_10 ) ;
V_14 = F_11 ( V_2 , V_11 , V_12 , V_13 ) ;
F_12 ( & V_2 -> V_10 ) ;
return V_14 ;
}
int F_11 ( struct V_1 * V_2 , unsigned int V_11 ,
unsigned int V_12 , unsigned int * V_13 )
{
unsigned int V_15 ;
int V_14 ;
if ( V_12 == ~ 0 )
return - V_16 ;
if ( V_13 )
* V_13 = - 1 ;
else if ( V_2 -> V_17 )
V_13 = & V_15 ;
for (; ; ) {
F_13 ( V_2 , V_12 ) ;
V_14 = V_2 -> V_6 -> V_18 ( V_2 , V_12 ) ;
if ( V_14 != - V_19 )
break;
V_14 = V_2 -> V_6 -> V_20 ( V_2 , V_11 , & V_15 ) ;
if ( V_14 )
break;
}
if ( ! V_14 && V_13 ) {
V_14 = V_2 -> V_6 -> V_20 ( V_2 , V_11 , V_13 ) ;
F_14 ( V_2 , V_11 , * V_13 ) ;
}
return V_14 ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_21 )
{
unsigned int V_22 ;
if ( ! V_2 )
return;
F_16 ( V_2 , V_13 , V_21 ) ;
V_22 = ( V_2 -> V_23 + 1 ) % V_24 ;
V_2 -> V_23 = V_22 ;
V_22 <<= 1 ;
V_2 -> V_25 [ V_22 ] = V_13 ;
V_2 -> V_25 [ V_22 + 1 ] = V_21 ;
F_17 ( & V_2 -> V_8 ) ;
}
static void V_9 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_18 ( V_27 , struct V_1 , V_8 ) ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
unsigned int V_32 , V_33 , V_13 ;
while ( V_2 -> V_34 != V_2 -> V_23 ) {
V_32 = ( V_2 -> V_34 + 1 ) % V_24 ;
V_2 -> V_34 = V_32 ;
V_32 <<= 1 ;
V_13 = V_2 -> V_25 [ V_32 ] ;
V_33 = V_2 -> V_25 [ V_32 + 1 ] ;
if ( ! ( V_33 & ( 1 << 4 ) ) )
continue;
V_29 = V_2 -> V_35 [ V_33 & 0x0f ] ;
if ( ! V_29 || ! V_29 -> V_4 . V_36 )
continue;
V_31 = F_19 ( V_29 -> V_4 . V_36 ) ;
if ( V_31 -> V_37 )
V_31 -> V_37 ( V_29 , V_13 ) ;
}
}
int F_20 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
if ( V_2 -> V_35 [ V_29 -> V_11 ] ) {
F_21 ( V_2 -> V_4 , L_1 ,
V_29 -> V_11 ) ;
return - V_38 ;
}
F_22 ( & V_29 -> V_39 , & V_2 -> V_7 ) ;
V_2 -> V_35 [ V_29 -> V_11 ] = V_29 ;
F_23 ( V_29 -> V_11 , & V_2 -> V_40 ) ;
V_2 -> V_41 ++ ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
F_6 ( V_2 != V_29 -> V_2 ) ;
if ( F_7 ( & V_29 -> V_39 ) )
return;
F_25 ( & V_29 -> V_39 ) ;
V_2 -> V_35 [ V_29 -> V_11 ] = NULL ;
F_26 ( V_29 -> V_11 , & V_2 -> V_40 ) ;
V_2 -> V_41 -- ;
}
