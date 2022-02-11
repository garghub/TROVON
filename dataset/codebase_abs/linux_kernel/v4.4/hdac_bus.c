int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_4 = V_4 ;
if ( V_6 )
V_2 -> V_6 = V_6 ;
else
V_2 -> V_6 = & V_9 ;
V_2 -> V_8 = V_8 ;
F_2 ( & V_2 -> V_10 ) ;
F_2 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_12 , V_13 ) ;
F_4 ( & V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_15 ) ;
V_2 -> V_16 = - 1 ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( ! F_8 ( & V_2 -> V_10 ) ) ;
F_7 ( ! F_8 ( & V_2 -> V_11 ) ) ;
F_9 ( & V_2 -> V_12 ) ;
}
int F_10 ( struct V_1 * V_2 , unsigned int V_17 ,
unsigned int V_18 , unsigned int * V_19 )
{
int V_20 ;
F_11 ( & V_2 -> V_15 ) ;
V_20 = F_12 ( V_2 , V_17 , V_18 , V_19 ) ;
F_13 ( & V_2 -> V_15 ) ;
return V_20 ;
}
int F_12 ( struct V_1 * V_2 , unsigned int V_17 ,
unsigned int V_18 , unsigned int * V_19 )
{
unsigned int V_21 ;
int V_20 ;
if ( V_18 == ~ 0 )
return - V_22 ;
if ( V_19 )
* V_19 = - 1 ;
else if ( V_2 -> V_23 )
V_19 = & V_21 ;
for (; ; ) {
F_14 ( V_2 , V_18 ) ;
V_20 = V_2 -> V_6 -> V_24 ( V_2 , V_18 ) ;
if ( V_20 != - V_25 )
break;
V_20 = V_2 -> V_6 -> V_26 ( V_2 , V_17 , & V_21 ) ;
if ( V_20 )
break;
}
if ( ! V_20 && V_19 ) {
V_20 = V_2 -> V_6 -> V_26 ( V_2 , V_17 , V_19 ) ;
F_15 ( V_2 , V_17 , * V_19 ) ;
}
return V_20 ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_27 )
{
unsigned int V_28 ;
if ( ! V_2 )
return;
F_17 ( V_2 , V_19 , V_27 ) ;
V_28 = ( V_2 -> V_29 + 1 ) % V_30 ;
V_2 -> V_29 = V_28 ;
V_28 <<= 1 ;
V_2 -> V_31 [ V_28 ] = V_19 ;
V_2 -> V_31 [ V_28 + 1 ] = V_27 ;
F_18 ( & V_2 -> V_12 ) ;
}
static void V_13 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_19 ( V_33 , struct V_1 , V_12 ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
unsigned int V_38 , V_39 , V_19 ;
while ( V_2 -> V_40 != V_2 -> V_29 ) {
V_38 = ( V_2 -> V_40 + 1 ) % V_30 ;
V_2 -> V_40 = V_38 ;
V_38 <<= 1 ;
V_19 = V_2 -> V_31 [ V_38 ] ;
V_39 = V_2 -> V_31 [ V_38 + 1 ] ;
if ( ! ( V_39 & ( 1 << 4 ) ) )
continue;
V_35 = V_2 -> V_41 [ V_39 & 0x0f ] ;
if ( ! V_35 || ! V_35 -> V_4 . V_42 )
continue;
V_37 = F_20 ( V_35 -> V_4 . V_42 ) ;
if ( V_37 -> V_43 )
V_37 -> V_43 ( V_35 , V_19 ) ;
}
}
int F_21 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
if ( V_2 -> V_41 [ V_35 -> V_17 ] ) {
F_22 ( V_2 -> V_4 , L_1 ,
V_35 -> V_17 ) ;
return - V_44 ;
}
F_23 ( & V_35 -> V_45 , & V_2 -> V_11 ) ;
V_2 -> V_41 [ V_35 -> V_17 ] = V_35 ;
F_24 ( V_35 -> V_17 , & V_2 -> V_46 ) ;
V_2 -> V_47 ++ ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
F_7 ( V_2 != V_35 -> V_2 ) ;
if ( F_8 ( & V_35 -> V_45 ) )
return;
F_26 ( & V_35 -> V_45 ) ;
V_2 -> V_41 [ V_35 -> V_17 ] = NULL ;
F_27 ( V_35 -> V_17 , & V_2 -> V_46 ) ;
V_2 -> V_47 -- ;
}
