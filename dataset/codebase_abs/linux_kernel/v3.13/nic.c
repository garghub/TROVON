int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , T_1 V_6 )
{
V_4 -> V_7 = F_2 ( & V_2 -> V_8 -> V_9 , V_5 ,
& V_4 -> V_10 , V_6 ) ;
if ( ! V_4 -> V_7 )
return - V_11 ;
V_4 -> V_5 = V_5 ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_7 ) {
F_4 ( & V_2 -> V_8 -> V_9 , V_4 -> V_5 ,
V_4 -> V_7 , V_4 -> V_10 ) ;
V_4 -> V_7 = NULL ;
}
}
bool F_5 ( struct V_12 * V_13 )
{
return F_6 ( F_7 ( V_13 , V_13 -> V_14 ) ) ;
}
void F_8 ( struct V_12 * V_13 )
{
V_13 -> V_15 = - 1 ;
F_9 () ;
V_13 -> V_2 -> type -> V_16 ( V_13 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_17 = - 1 ;
F_9 () ;
V_2 -> type -> V_18 ( V_2 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
unsigned int V_19 ;
int V_20 ;
if ( ! F_12 ( V_2 ) ) {
V_20 = F_13 ( V_2 -> V_21 ,
V_2 -> type -> V_22 , V_23 ,
V_2 -> V_24 , V_2 ) ;
if ( V_20 ) {
F_14 ( V_2 , V_25 , V_2 -> V_26 ,
L_1 ,
V_2 -> V_8 -> V_27 ) ;
goto V_28;
}
return 0 ;
}
#ifdef F_15
if ( V_2 -> V_29 == V_30 ) {
V_2 -> V_26 -> V_31 =
F_16 ( V_2 -> V_32 ) ;
if ( ! V_2 -> V_26 -> V_31 ) {
V_20 = - V_11 ;
goto V_28;
}
}
#endif
V_19 = 0 ;
F_17 (channel, efx) {
V_20 = F_13 ( V_13 -> V_27 , V_2 -> type -> V_33 ,
V_34 ,
V_2 -> V_35 [ V_13 -> V_13 ] . V_24 ,
& V_2 -> V_35 [ V_13 -> V_13 ] ) ;
if ( V_20 ) {
F_14 ( V_2 , V_25 , V_2 -> V_26 ,
L_2 , V_13 -> V_27 ) ;
goto V_36;
}
++ V_19 ;
#ifdef F_15
if ( V_2 -> V_29 == V_30 &&
V_13 -> V_13 < V_2 -> V_32 ) {
V_20 = F_18 ( V_2 -> V_26 -> V_31 ,
V_13 -> V_27 ) ;
if ( V_20 )
goto V_36;
}
#endif
}
return 0 ;
V_36:
#ifdef F_15
F_19 ( V_2 -> V_26 -> V_31 ) ;
V_2 -> V_26 -> V_31 = NULL ;
#endif
F_17 (channel, efx) {
if ( V_19 -- == 0 )
break;
F_20 ( V_13 -> V_27 , & V_2 -> V_35 [ V_13 -> V_13 ] ) ;
}
V_28:
return V_20 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
#ifdef F_15
F_19 ( V_2 -> V_26 -> V_31 ) ;
V_2 -> V_26 -> V_31 = NULL ;
#endif
F_17 (channel, efx)
F_20 ( V_13 -> V_27 , & V_2 -> V_35 [ V_13 -> V_13 ] ) ;
if ( V_2 -> V_21 )
F_20 ( V_2 -> V_21 , V_2 ) ;
}
T_2 F_22 ( struct V_1 * V_2 )
{
const struct V_37 * V_38 ;
const struct V_39 * V_40 ;
T_2 V_5 = 0 ;
for ( V_38 = V_41 ;
V_38 < V_41 + F_23 ( V_41 ) ;
V_38 ++ )
if ( V_2 -> type -> V_42 >= V_38 -> V_43 &&
V_2 -> type -> V_42 <= V_38 -> V_44 )
V_5 += sizeof( V_45 ) ;
for ( V_40 = V_46 ;
V_40 < V_46 + F_23 ( V_46 ) ;
V_40 ++ )
if ( V_2 -> type -> V_42 >= V_40 -> V_43 &&
V_2 -> type -> V_42 <= V_40 -> V_44 )
V_5 += V_40 -> V_47 * F_24 ( T_2 , V_40 -> V_48 , 16 ) ;
return V_5 ;
}
void F_25 ( struct V_1 * V_2 , void * V_49 )
{
const struct V_37 * V_38 ;
const struct V_39 * V_40 ;
for ( V_38 = V_41 ;
V_38 < V_41 + F_23 ( V_41 ) ;
V_38 ++ ) {
if ( V_2 -> type -> V_42 >= V_38 -> V_43 &&
V_2 -> type -> V_42 <= V_38 -> V_44 ) {
F_26 ( V_2 , ( V_45 * ) V_49 , V_38 -> V_50 ) ;
V_49 += sizeof( V_45 ) ;
}
}
for ( V_40 = V_46 ;
V_40 < V_46 + F_23 ( V_46 ) ;
V_40 ++ ) {
T_2 V_51 , V_52 ;
if ( ! ( V_2 -> type -> V_42 >= V_40 -> V_43 &&
V_2 -> type -> V_42 <= V_40 -> V_44 ) )
continue;
V_51 = F_24 ( T_2 , V_40 -> V_48 , 16 ) ;
for ( V_52 = 0 ; V_52 < V_40 -> V_47 ; V_52 ++ ) {
switch ( V_40 -> V_48 ) {
case 4 :
F_27 ( V_2 , V_49 , V_40 -> V_50 + 4 * V_52 ) ;
break;
case 8 :
F_28 ( V_2 ,
V_2 -> V_53 + V_40 -> V_50 ,
V_49 , V_52 ) ;
break;
case 16 :
F_29 ( V_2 , V_49 , V_40 -> V_50 , V_52 ) ;
break;
case 32 :
F_29 ( V_2 , V_49 , V_40 -> V_50 , 2 * V_52 ) ;
break;
default:
F_30 ( 1 ) ;
return;
}
V_49 += V_51 ;
}
}
}
T_2 F_31 ( const struct V_54 * V_55 , T_2 V_56 ,
const unsigned long * V_57 , T_3 * V_58 )
{
T_2 V_59 = 0 ;
T_2 V_60 ;
F_32 (index, mask, count) {
if ( V_55 [ V_60 ] . V_24 ) {
if ( V_58 ) {
F_33 ( V_58 , V_55 [ V_60 ] . V_24 ,
V_61 ) ;
V_58 += V_61 ;
}
++ V_59 ;
}
}
return V_59 ;
}
void F_34 ( const struct V_54 * V_55 , T_2 V_56 ,
const unsigned long * V_57 ,
T_4 * V_62 , const void * V_63 , bool V_64 )
{
T_2 V_60 ;
F_32 (index, mask, count) {
if ( V_55 [ V_60 ] . V_65 ) {
const void * V_7 = V_63 + V_55 [ V_60 ] . V_50 ;
T_4 V_66 ;
switch ( V_55 [ V_60 ] . V_65 ) {
case 16 :
V_66 = F_35 ( ( V_67 * ) V_7 ) ;
break;
case 32 :
V_66 = F_36 ( ( V_68 * ) V_7 ) ;
break;
case 64 :
V_66 = F_37 ( ( V_69 * ) V_7 ) ;
break;
default:
F_30 ( 1 ) ;
V_66 = 0 ;
break;
}
if ( V_64 )
V_62 [ V_60 ] += V_66 ;
else
V_62 [ V_60 ] = V_66 ;
}
}
}
