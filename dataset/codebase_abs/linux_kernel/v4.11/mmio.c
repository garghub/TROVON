int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = * ( T_1 * ) ( F_2 ( V_2 ) + V_5 ) &
~ F_3 ( 3 , 0 ) ;
return V_3 - V_4 ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_6 ,
void * V_7 , unsigned int V_8 , bool V_9 )
{
struct V_10 * V_11 = NULL ;
void * V_12 = NULL ;
unsigned int V_13 = 0 ;
if ( ! V_2 || ! V_7 )
return;
V_11 = V_2 -> V_11 ;
F_5 ( & V_11 -> V_14 ) ;
V_13 = F_1 ( V_2 , V_6 ) ;
if ( F_6 ( V_11 , V_13 ) ) {
if ( V_9 )
F_7 ( V_2 , V_13 , V_7 ,
V_8 ) ;
else
F_8 ( V_2 , V_13 , V_7 ,
V_8 ) ;
} else if ( F_9 ( V_11 , V_13 ) &&
V_2 -> V_15 . V_16 -> V_17 ) {
V_13 -= V_11 -> V_18 . V_19 ;
V_12 = V_2 -> V_15 . V_16 -> V_17 + V_13 ;
if ( V_9 )
memcpy ( V_7 , V_12 , V_8 ) ;
else
memcpy ( V_12 , V_7 , V_8 ) ;
} else if ( F_10 ( & V_2 -> V_15 . V_20 ) ) {
struct V_21 * V_22 ;
V_22 = F_11 ( V_2 , V_6 >> V_23 ) ;
if ( V_22 ) {
F_12 ( V_2 , V_22 ) ;
if ( V_9 )
F_13 ( V_2 , V_6 ,
V_7 , V_8 ) ;
else
F_14 ( V_2 , V_6 ,
V_7 , V_8 ) ;
}
}
F_15 ( & V_11 -> V_14 ) ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_6 ,
void * V_7 , unsigned int V_8 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_24 * V_25 ;
unsigned int V_13 = 0 ;
int V_26 = - V_27 ;
if ( V_2 -> V_28 ) {
F_4 ( V_2 , V_6 , V_7 , V_8 , true ) ;
return 0 ;
}
F_5 ( & V_11 -> V_14 ) ;
if ( F_10 ( & V_2 -> V_15 . V_20 ) ) {
struct V_21 * V_22 ;
V_22 = F_11 ( V_2 , V_6 >> V_23 ) ;
if ( V_22 ) {
V_26 = F_13 ( V_2 , V_6 ,
V_7 , V_8 ) ;
if ( V_26 ) {
F_17 ( L_1
L_2 ,
V_26 , V_22 -> V_29 , V_6 , * ( V_30 * ) V_7 ,
V_8 ) ;
}
F_15 ( & V_11 -> V_14 ) ;
return V_26 ;
}
}
V_13 = F_1 ( V_2 , V_6 ) ;
if ( F_18 ( V_8 > 8 ) )
goto V_31;
if ( F_9 ( V_11 , V_13 ) ) {
if ( F_18 ( ! F_19 ( V_13 , 4 ) && ! F_19 ( V_13 , 8 ) ) )
goto V_31;
if ( F_18 ( V_8 != 4 && V_8 != 8 ) )
goto V_31;
if ( F_18 ( ! F_9 ( V_11 , V_13 + V_8 - 1 ) ) )
goto V_31;
V_26 = F_20 ( V_2 , V_13 ,
V_7 , V_8 ) ;
if ( V_26 )
goto V_31;
F_15 ( & V_11 -> V_14 ) ;
return V_26 ;
}
if ( F_21 ( ! F_6 ( V_11 , V_13 ) ) ) {
V_26 = F_13 ( V_2 , V_6 , V_7 , V_8 ) ;
F_15 ( & V_11 -> V_14 ) ;
return V_26 ;
}
if ( F_18 ( ! F_6 ( V_11 , V_13 + V_8 - 1 ) ) )
goto V_31;
if ( ! F_22 ( V_11 , V_13 ) ) {
if ( F_18 ( ! F_19 ( V_13 , V_8 ) ) )
goto V_31;
}
V_25 = F_23 ( V_11 , F_24 ( V_13 , 4 ) ) ;
if ( V_25 ) {
if ( ! F_22 ( V_11 , V_25 -> V_13 ) ) {
if ( F_18 ( V_13 + V_8 > V_25 -> V_13 + V_25 -> V_32 ) )
goto V_31;
if ( F_18 ( V_25 -> V_13 != V_13 ) )
goto V_31;
}
V_26 = V_25 -> V_9 ( V_2 , V_13 , V_7 , V_8 ) ;
} else {
V_26 = F_7 ( V_2 , V_13 , V_7 , V_8 ) ;
if ( ! V_2 -> V_25 . V_33 ) {
F_17 ( L_3 ,
V_13 , V_8 , * ( V_30 * ) V_7 ) ;
if ( V_13 == 0x206c ) {
F_17 ( L_4 ) ;
F_17 ( L_5 ) ;
F_17 ( L_4 ) ;
V_2 -> V_25 . V_33 = true ;
}
}
}
if ( V_26 )
goto V_31;
F_25 ( V_11 , V_13 ) ;
F_15 ( & V_11 -> V_14 ) ;
return 0 ;
V_31:
F_17 ( L_6 ,
V_13 , V_8 ) ;
F_15 ( & V_11 -> V_14 ) ;
return V_26 ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_6 ,
void * V_7 , unsigned int V_8 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_24 * V_25 ;
unsigned int V_13 = 0 ;
V_30 V_34 = 0 , V_35 = 0 ;
int V_26 = - V_27 ;
if ( V_2 -> V_28 ) {
F_4 ( V_2 , V_6 , V_7 , V_8 , false ) ;
return 0 ;
}
F_5 ( & V_11 -> V_14 ) ;
if ( F_10 ( & V_2 -> V_15 . V_20 ) ) {
struct V_21 * V_22 ;
V_22 = F_11 ( V_2 , V_6 >> V_23 ) ;
if ( V_22 ) {
V_26 = V_22 -> V_36 ( V_22 , V_6 , V_7 , V_8 ) ;
if ( V_26 ) {
F_27 ( L_7
L_8
L_9 ,
V_26 , V_22 -> V_29 , V_6 ,
* ( V_30 * ) V_7 , V_8 ) ;
}
F_15 ( & V_11 -> V_14 ) ;
return V_26 ;
}
}
V_13 = F_1 ( V_2 , V_6 ) ;
if ( F_18 ( V_8 > 8 ) )
goto V_31;
if ( F_9 ( V_11 , V_13 ) ) {
if ( F_18 ( ! F_19 ( V_13 , 4 ) && ! F_19 ( V_13 , 8 ) ) )
goto V_31;
if ( F_18 ( V_8 != 4 && V_8 != 8 ) )
goto V_31;
if ( F_18 ( ! F_9 ( V_11 , V_13 + V_8 - 1 ) ) )
goto V_31;
V_26 = F_28 ( V_2 , V_13 ,
V_7 , V_8 ) ;
if ( V_26 )
goto V_31;
F_15 ( & V_11 -> V_14 ) ;
return V_26 ;
}
if ( F_21 ( ! F_6 ( V_11 , V_13 ) ) ) {
V_26 = F_14 ( V_2 , V_6 , V_7 , V_8 ) ;
F_15 ( & V_11 -> V_14 ) ;
return V_26 ;
}
V_25 = F_23 ( V_11 , F_24 ( V_13 , 4 ) ) ;
if ( ! V_25 && ! V_2 -> V_25 . V_33 )
F_29 ( L_10 ,
V_2 -> V_37 , V_13 , V_8 , * ( V_30 * ) V_7 ) ;
if ( ! F_22 ( V_11 , V_13 ) ) {
if ( F_18 ( ! F_19 ( V_13 , V_8 ) ) )
goto V_31;
}
if ( V_25 ) {
T_1 V_38 = V_25 -> V_38 ;
if ( ! F_22 ( V_11 , V_25 -> V_13 ) ) {
if ( F_18 ( V_13 + V_8 > V_25 -> V_13 + V_25 -> V_32 ) )
goto V_31;
if ( F_18 ( V_25 -> V_13 != V_13 ) )
goto V_31;
}
if ( F_30 ( V_11 , V_25 -> V_13 ) ) {
V_34 = F_31 ( V_2 , V_13 ) ;
V_35 = F_32 ( V_2 , V_13 ) ;
}
if ( ! V_38 ) {
V_26 = V_25 -> V_39 ( V_2 , V_13 , V_7 , V_8 ) ;
} else {
T_1 V_40 = 0 ;
if ( V_38 == ~ ( T_1 ) 0 ) {
F_17 ( L_11 ,
V_13 ) ;
V_26 = 0 ;
goto V_41;
}
memcpy ( & V_40 , V_7 , V_8 ) ;
V_40 &= ~ V_25 -> V_38 ;
V_40 |= F_31 ( V_2 , V_13 ) & V_25 -> V_38 ;
V_26 = V_25 -> V_39 ( V_2 , V_13 , & V_40 , V_8 ) ;
}
if ( F_30 ( V_11 , V_25 -> V_13 ) ) {
V_30 V_42 = F_31 ( V_2 , V_13 ) >> 16 ;
F_31 ( V_2 , V_13 ) = ( V_34 & ~ V_42 )
| ( F_31 ( V_2 , V_13 ) & V_42 ) ;
F_32 ( V_2 , V_13 ) = ( V_35 & ~ V_42 )
| ( F_32 ( V_2 , V_13 ) & V_42 ) ;
}
} else
V_26 = F_8 ( V_2 , V_13 , V_7 ,
V_8 ) ;
if ( V_26 )
goto V_31;
V_41:
F_25 ( V_11 , V_13 ) ;
F_15 ( & V_11 -> V_14 ) ;
return 0 ;
V_31:
F_17 ( L_12 , V_13 ,
V_8 ) ;
F_15 ( & V_11 -> V_14 ) ;
return V_26 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_43 * V_44 = & V_11 -> V_18 ;
memcpy ( V_2 -> V_25 . V_45 , V_11 -> V_46 . V_25 , V_44 -> V_47 ) ;
memcpy ( V_2 -> V_25 . V_48 , V_11 -> V_46 . V_25 , V_44 -> V_47 ) ;
F_31 ( V_2 , V_49 ) = 0 ;
F_31 ( V_2 , V_50 ) = 0 ;
V_2 -> V_25 . V_33 = false ;
}
int F_34 ( struct V_1 * V_2 )
{
const struct V_43 * V_44 = & V_2 -> V_11 -> V_18 ;
V_2 -> V_25 . V_45 = F_35 ( V_44 -> V_47 * 2 ) ;
if ( ! V_2 -> V_25 . V_45 )
return - V_51 ;
V_2 -> V_25 . V_48 = V_2 -> V_25 . V_45 + V_44 -> V_47 ;
F_33 ( V_2 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( V_2 -> V_25 . V_45 ) ;
V_2 -> V_25 . V_45 = V_2 -> V_25 . V_48 = NULL ;
}
