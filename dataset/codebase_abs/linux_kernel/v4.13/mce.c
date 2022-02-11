static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_5 = (struct V_5 * ) V_4 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
if ( ! F_2 ( V_5 ) )
return V_9 ;
F_3 ( & V_10 ) ;
F_4 (acpi_desc, &acpi_descs, list) {
struct V_11 * V_12 = V_7 -> V_12 ;
int V_13 = 0 ;
F_3 ( & V_7 -> V_14 ) ;
F_4 (nfit_spa, &acpi_desc->spas, list) {
struct V_15 * V_16 = V_8 -> V_16 ;
if ( F_5 ( V_16 ) != V_17 )
continue;
if ( V_16 -> V_18 > V_5 -> V_19 )
continue;
if ( ( V_16 -> V_18 + V_16 -> V_20 - 1 ) < V_5 -> V_19 )
continue;
V_13 = 1 ;
F_6 ( V_12 , L_1 ,
V_21 , V_16 -> V_22 , V_16 -> V_18 ,
V_16 -> V_20 ) ;
break;
}
F_7 ( & V_7 -> V_14 ) ;
if ( ! V_13 )
continue;
F_8 ( V_7 -> V_23 ,
F_9 ( V_5 -> V_19 , V_24 ) ,
V_24 ) ;
F_10 ( V_8 -> V_25 ,
V_26 ) ;
if ( V_7 -> V_27 == V_28 ) {
F_11 ( V_7 , 0 ) ;
}
break;
}
F_7 ( & V_10 ) ;
return V_9 ;
}
void F_12 ( void )
{
F_13 ( & V_29 ) ;
}
void F_14 ( void )
{
F_15 ( & V_29 ) ;
}
