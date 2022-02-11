static int T_1 F_1 ( void )
{
int V_1 = 0 ;
V_1 = F_2 () ;
if ( V_1 )
return V_1 ;
V_1 = F_3 () ;
if ( V_1 )
goto V_2;
V_1 = F_4 () ;
if ( V_1 )
goto V_3;
return V_1 ;
V_3:
F_5 () ;
V_2:
F_6 () ;
return V_1 ;
}
static void T_2 F_7 ( void )
{
F_6 () ;
F_5 () ;
F_8 () ;
}
T_3 F_9 ( void * V_4 , T_4 V_5 ,
struct V_6 * V_7 ,
T_3 * V_8 , T_4 * V_9 ,
enum V_10 V_10 , T_3 * V_11 )
{
T_4 V_12 = V_5 ;
T_3 V_13 = 0 ;
while ( V_12 > 0 && V_7 ) {
T_4 V_14 , V_15 ;
void * V_16 ;
if ( * V_9 >= V_7 -> V_17 ) {
if ( ! ( * V_8 ) )
break;
-- ( * V_8 ) ;
* V_9 -= V_7 -> V_17 ;
V_7 = F_10 ( V_7 ) ;
continue;
}
V_15 = F_11 ( V_12 , V_7 -> V_17 - * V_9 ) ;
V_14 = * V_9 + V_7 -> V_9 ;
V_15 = F_11 ( V_15 ,
( T_4 ) ( V_18 - ( V_14 & ~ V_19 ) ) ) ;
V_16 = F_12 ( F_13 ( V_7 ) + ( V_14 >> V_20 ) ,
V_10 ) ;
if ( V_11 )
* V_11 = F_14 ( * V_11 , V_4 , V_15 ) ;
memcpy ( ( char * ) V_16 + ( V_14 & ~ V_19 ) , V_4 , V_15 ) ;
F_15 ( V_16 , V_10 ) ;
V_4 += V_15 ;
* V_9 += V_15 ;
V_12 -= V_15 ;
V_13 += V_15 ;
}
return V_13 ;
}
void F_16 ( struct V_21 * V_22 , const struct V_21 * V_23 ,
enum V_24 V_25 , T_3 V_26 , T_5 V_27 , T_3 V_28 )
{
struct V_29 * V_30 ;
struct V_29 * V_31 ;
struct V_32 * V_33 ;
T_3 V_34 ;
V_30 = F_17 ( V_22 ) ;
V_31 = F_17 ( V_23 ) ;
if ( V_26 & V_35 ) {
V_34 = - F_18 ( V_22 ) & 3 ;
if ( V_34 ) {
memset ( F_19 ( F_20 ( V_22 ) , V_34 ) , 0 , V_34 ) ;
V_26 |= V_34 ;
}
F_21 ( V_22 ) = V_36 ;
} else {
F_22 ( F_18 ( V_22 ) % 4 != 0 ) ;
F_21 ( V_22 ) = V_37 ;
}
V_30 -> V_38 = V_25 ;
memcpy ( V_30 -> V_39 , V_31 -> V_40 , sizeof( V_30 -> V_39 ) ) ;
memcpy ( V_30 -> V_40 , V_31 -> V_39 , sizeof( V_30 -> V_40 ) ) ;
V_30 -> V_41 = V_31 -> V_41 ;
F_23 ( V_30 -> V_42 , V_26 ) ;
V_30 -> V_43 = V_31 -> V_43 ;
V_30 -> V_44 = V_31 -> V_44 ;
V_30 -> V_45 = 0 ;
V_30 -> V_46 = 0 ;
V_30 -> V_47 = F_24 ( V_28 ) ;
V_33 = F_25 ( V_23 ) ;
if ( V_33 ) {
F_25 ( V_22 ) = V_33 ;
V_30 -> V_48 = V_33 -> V_49 ;
V_27 = V_33 -> V_50 ;
} else {
V_30 -> V_48 = 0 ;
}
V_30 -> V_51 = F_26 ( V_27 ) ;
F_27 ( V_22 ) = V_27 ? V_52 : V_53 ;
F_28 ( V_22 ) = F_28 ( V_23 ) ;
}
void F_29 ( struct V_21 * V_22 , const struct V_21 * V_23 ,
enum V_24 V_25 , T_3 V_28 )
{
struct V_32 * V_33 ;
V_33 = F_25 ( V_23 ) ;
if ( V_33 )
F_25 ( V_22 ) = F_30 ( V_23 ) -> V_54 . V_55 ( V_33 ) ;
F_16 ( V_22 , V_23 , V_25 , V_56 , 0 , V_28 ) ;
}
void F_31 ( struct V_57 * V_58 , enum V_59 type )
{
struct V_60 * V_61 ;
F_32 ( type >= V_62 ) ;
F_32 ( ! V_58 ) ;
V_61 = V_63 [ type ] ;
if ( type == V_64 ) {
if ( V_61 && V_61 -> V_65 )
V_58 -> V_66 |= V_67 ;
}
}
void F_33 ( void (* F_34)( struct V_57 * , void * ) , void * V_68 )
{
struct V_57 * V_58 ;
F_35 ( & V_69 ) ;
F_36 (lport, &fc_local_ports, lport_list)
F_34 ( V_58 , V_68 ) ;
F_37 ( & V_69 ) ;
}
int F_38 ( enum V_59 type , struct V_60 * V_70 )
{
struct V_60 * * V_61 ;
int V_71 = 0 ;
if ( type >= V_62 )
return - V_72 ;
F_35 ( & V_69 ) ;
V_61 = ( V_70 -> V_65 ? V_63 : V_73 ) + type ;
if ( * V_61 )
V_71 = - V_74 ;
else
* V_61 = V_70 ;
F_37 ( & V_69 ) ;
return V_71 ;
}
void F_39 ( enum V_59 type , struct V_60 * V_70 )
{
F_32 ( type >= V_62 ) ;
F_35 ( & V_69 ) ;
if ( V_70 -> V_65 )
F_40 ( V_63 [ type ] , NULL ) ;
else
F_40 ( V_73 [ type ] , NULL ) ;
F_37 ( & V_69 ) ;
F_41 () ;
}
void F_42 ( struct V_57 * V_58 )
{
F_35 ( & V_69 ) ;
F_43 ( & V_58 -> V_75 , & V_76 ) ;
F_44 ( & V_77 ,
V_78 , V_58 ) ;
F_37 ( & V_69 ) ;
}
void F_45 ( struct V_57 * V_58 )
{
F_35 ( & V_69 ) ;
F_46 ( & V_58 -> V_75 ) ;
F_44 ( & V_77 ,
V_79 , V_58 ) ;
F_37 ( & V_69 ) ;
}
