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
T_3 * V_10 )
{
T_4 V_11 = V_5 ;
T_3 V_12 = 0 ;
while ( V_11 > 0 && V_7 ) {
T_4 V_13 , V_14 ;
void * V_15 ;
if ( * V_9 >= V_7 -> V_16 ) {
if ( ! ( * V_8 ) )
break;
-- ( * V_8 ) ;
* V_9 -= V_7 -> V_16 ;
V_7 = F_10 ( V_7 ) ;
continue;
}
V_14 = F_11 ( V_11 , V_7 -> V_16 - * V_9 ) ;
V_13 = * V_9 + V_7 -> V_9 ;
V_14 = F_11 ( V_14 ,
( T_4 ) ( V_17 - ( V_13 & ~ V_18 ) ) ) ;
V_15 = F_12 ( F_13 ( V_7 ) + ( V_13 >> V_19 ) ) ;
if ( V_10 )
* V_10 = F_14 ( * V_10 , V_4 , V_14 ) ;
memcpy ( ( char * ) V_15 + ( V_13 & ~ V_18 ) , V_4 , V_14 ) ;
F_15 ( V_15 ) ;
V_4 += V_14 ;
* V_9 += V_14 ;
V_11 -= V_14 ;
V_12 += V_14 ;
}
return V_12 ;
}
void F_16 ( struct V_20 * V_21 , const struct V_20 * V_22 ,
enum V_23 V_24 , T_3 V_25 , T_5 V_26 , T_3 V_27 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_31 * V_32 ;
T_3 V_33 ;
V_29 = F_17 ( V_21 ) ;
V_30 = F_17 ( V_22 ) ;
if ( V_25 & V_34 ) {
V_33 = - F_18 ( V_21 ) & 3 ;
if ( V_33 ) {
memset ( F_19 ( F_20 ( V_21 ) , V_33 ) , 0 , V_33 ) ;
V_25 |= V_33 ;
}
F_21 ( V_21 ) = V_35 ;
} else {
F_22 ( F_18 ( V_21 ) % 4 != 0 ) ;
F_21 ( V_21 ) = V_36 ;
}
V_29 -> V_37 = V_24 ;
memcpy ( V_29 -> V_38 , V_30 -> V_39 , sizeof( V_29 -> V_38 ) ) ;
memcpy ( V_29 -> V_39 , V_30 -> V_38 , sizeof( V_29 -> V_39 ) ) ;
V_29 -> V_40 = V_30 -> V_40 ;
F_23 ( V_29 -> V_41 , V_25 ) ;
V_29 -> V_42 = V_30 -> V_42 ;
V_29 -> V_43 = V_30 -> V_43 ;
V_29 -> V_44 = 0 ;
V_29 -> V_45 = 0 ;
V_29 -> V_46 = F_24 ( V_27 ) ;
V_32 = F_25 ( V_22 ) ;
if ( V_32 ) {
F_25 ( V_21 ) = V_32 ;
V_29 -> V_47 = V_32 -> V_48 ;
V_26 = V_32 -> V_49 ;
} else {
V_29 -> V_47 = 0 ;
}
V_29 -> V_50 = F_26 ( V_26 ) ;
F_27 ( V_21 ) = V_26 ? V_51 : V_52 ;
F_28 ( V_21 ) = F_28 ( V_22 ) ;
}
void F_29 ( struct V_20 * V_21 , const struct V_20 * V_22 ,
enum V_23 V_24 , T_3 V_27 )
{
struct V_31 * V_32 ;
V_32 = F_25 ( V_22 ) ;
if ( V_32 )
F_25 ( V_21 ) = F_30 ( V_22 ) -> V_53 . V_54 ( V_32 ) ;
F_16 ( V_21 , V_22 , V_24 , V_55 , 0 , V_27 ) ;
}
void F_31 ( struct V_56 * V_57 , enum V_58 type )
{
struct V_59 * V_60 ;
F_32 ( type >= V_61 ) ;
F_32 ( ! V_57 ) ;
V_60 = V_62 [ type ] ;
if ( type == V_63 ) {
if ( V_60 && V_60 -> V_64 )
V_57 -> V_65 |= V_66 ;
}
}
void F_33 ( void (* F_34)( struct V_56 * , void * ) , void * V_67 )
{
struct V_56 * V_57 ;
F_35 ( & V_68 ) ;
F_36 (lport, &fc_local_ports, lport_list)
F_34 ( V_57 , V_67 ) ;
F_37 ( & V_68 ) ;
}
int F_38 ( enum V_58 type , struct V_59 * V_69 )
{
struct V_59 * * V_60 ;
int V_70 = 0 ;
if ( type >= V_61 )
return - V_71 ;
F_35 ( & V_68 ) ;
V_60 = ( V_69 -> V_64 ? V_62 : V_72 ) + type ;
if ( * V_60 )
V_70 = - V_73 ;
else
* V_60 = V_69 ;
F_37 ( & V_68 ) ;
return V_70 ;
}
void F_39 ( enum V_58 type , struct V_59 * V_69 )
{
F_32 ( type >= V_61 ) ;
F_35 ( & V_68 ) ;
if ( V_69 -> V_64 )
F_40 ( V_62 [ type ] , NULL ) ;
else
F_40 ( V_72 [ type ] , NULL ) ;
F_37 ( & V_68 ) ;
F_41 () ;
}
void F_42 ( struct V_56 * V_57 )
{
F_35 ( & V_68 ) ;
F_43 ( & V_57 -> V_74 , & V_75 ) ;
F_44 ( & V_76 ,
V_77 , V_57 ) ;
F_37 ( & V_68 ) ;
}
void F_45 ( struct V_56 * V_57 )
{
F_35 ( & V_68 ) ;
F_46 ( & V_57 -> V_74 ) ;
F_44 ( & V_76 ,
V_78 , V_57 ) ;
F_37 ( & V_68 ) ;
}
